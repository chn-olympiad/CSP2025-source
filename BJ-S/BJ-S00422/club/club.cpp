#include<bits/stdc++.h>
using namespace std;
int aa[100005],bb[100005],cc[100005];
int a[100005],b[100005],c[100005];
stack<int> ma,mb,mc;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        ma.push(0);
        mb.push(0);
        mc.push(0);
        a[0]=b[0]=c[0]=20005;
        for(int i=1;i<=n;i++){
            cin>>aa[i]>>bb[i]>>cc[i];
            a[i]=aa[i]-(aa[i]+bb[i]+cc[i]-max(aa[i],max(bb[i],cc[i]))-min(aa[i],min(bb[i],cc[i])));
            b[i]=bb[i]-(aa[i]+bb[i]+cc[i]-max(aa[i],max(bb[i],cc[i]))-min(aa[i],min(bb[i],cc[i])));
            c[i]=cc[i]-(aa[i]+bb[i]+cc[i]-max(aa[i],max(bb[i],cc[i]))-min(aa[i],min(bb[i],cc[i])));
        }
        int qa=0,qb=0,qc=0,ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=b[i] && a[i]>=c[i]){
                qa++;
                ans+=aa[i];
                if(a[i]<a[ma.top()]){
                    ma.push(i);
                }
                else if(a[i]==a[ma.top()]){
                    if(max(b[ma.top()],c[ma.top()])<=max(b[i],c[i])) ma.push(i);
                }
                //cout<<1<<endl;
                //cout<<aa[ma.top()]<<endl;
            }
            else if(c[i]>=b[i] && a[i]<=c[i]){
                qc++;
                ans+=cc[i];
                if(c[i]<c[mc.top()]){
                    mc.push(i);
                }
                else if(c[i]==c[mc.top()]){
                    if(max(b[mc.top()],a[mc.top()])<=max(b[i],a[i])) mc.push(i);
                }
                //cout<<3<<endl;
                //cout<<c[mc.top()]<<'<'<<c[i]<<' '<<cc[i]<<endl;
            }
            else{
                qb++;
                ans+=bb[i];
                if(b[i]<b[mb.top()]){
                    mb.push(i);
                }
                else if(b[i]==b[mb.top()]){
                    if(max(a[mb.top()],c[mb.top()])<=max(a[i],c[i])) mb.push(i);
                }
                //cout<<2<<endl;
                //cout<<bb[mb.top()]<<endl;
            }
            if(qa > n/2){
                //cout<<1<<' '<<ma.top()<<endl;
                //cout<<ans<<endl;
                qa--;
                ans=ans-aa[ma.top()];
                //cout<<ans<<endl;
                if((b[ma.top()]>=c[ma.top()] && qb<=n/2) || qc==n/2){
                    ans+=bb[ma.top()];
                    qb++;
                    //cout<<2<<endl;
                }
                else{
                    qc++;
                    ans+=cc[ma.top()];
                    //cout<<3<<endl;
                }
                ma.pop();
            }//
            if(qb > n/2){
                //cout<<2<<' '<<mb.top()<<endl;
                qb--;
                ans=ans-bb[mb.top()];
                if((a[mb.top()]>=c[mb.top()] && qa<=n/2) || qc==n/2){
                    ans+=aa[mb.top()];
                    qa++;
                    //cout<<1<<endl;
                }
                else{
                    qc++;
                    ans+=cc[mb.top()];
                    //cout<<3<<endl;
                }
                mb.pop();
            }//
            if(qc > n/2){
                //cout<<3<<' '<<mc.top()<<endl;
                qc--;
                ans=ans-cc[mc.top()];
                if((a[mc.top()]>=b[mc.top()] && qa<=n/2) || qb==n/2){
                    ans+=aa[mc.top()];
                    qa++;
                    //cout<<1<<endl;
                }
                else{
                    qb++;
                    ans+=bb[mc.top()];
                    //cout<<2<<endl;
                }
                mc.pop();
            }
            //cout<<ma[i]<<' '<<mb[i]<<' '<<mc[i]<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
