#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){int a[100005]={},b[100005]={},c[100005]={},aa[100005]={},bb[100005]={},cc[100005]={},aaa[100005]={},bbb[100005]={},ccc[100005]={};
        int n,ans=0,cnta=0,cntb=0,cntc=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        int mx=max(a[i],max(b[i],c[i]));
        if(mx==a[i])
        ans+=a[i],cnta++,aa[cnta]=a[i]-max(b[i],c[i]),aaa[cnta]=1;//,cout<<cnta<<' '<<aa[cnta]<<endl;
        else if(mx==b[i])
        ans+=b[i],cntb++,bb[cntb]=b[i]-max(a[i],c[i]),bbb[cntb]=1;
        else{

            ans+=c[i],cntc++,cc[cntc]=c[i]-max(b[i],a[i]),ccc[cntc]=1;
        }

    }
    sort(aa+1,aa+cnta+1);
    sort(bb+1,bb+cntb+1);
    sort(cc+1,cc+cntc+1);
    int xb=1;
    if(cnta>n/2){
        while(cnta>n/2){
             if(aaa[xb]){//cout<<'*'<<xb<<' '<<ans<<endl;
                ans-=aa[xb++];

             cnta--;
            }else xb++;
        }
    }
    else if(cntb>n/2){
        while(cntb>n/2){
             if(bbb[xb]){
                ans-=bb[xb++];
                //out<<'^'<<ans<<endl;
             cntb--;
            }else xb++;
        }
    }
    else if(cntc>n/2){
        while(cntc>n/2){
            if(ccc[xb]){//cout<<'&'<<ans<<endl;
                ans-=cc[xb++];

             cntc--;
            }else xb++;

        }
    }
    cout<<ans<<endl;
    }

    return 0;
}
