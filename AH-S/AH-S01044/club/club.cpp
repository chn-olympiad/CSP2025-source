#include<bits/stdc++.h>
using namespace std;
long long n,T;
struct node{
    long long v,v1,ss;
}x[100005],y[100005],z[100005];
long long cnt1,cnt2,cnt3;
bool cmp(node x,node y){
    return x.ss>y.ss;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        cnt1=cnt2=cnt3=0;
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(z,0,sizeof(z));
        for(int i=1,a,b,c;i<=n;i++){
            cin>>a>>b>>c;
            long long minn=min(a,min(b,c));
            if(a==minn){
                if(b<c){
                    cnt3++;
                    z[cnt3].v=c,z[cnt3].v1=b,z[cnt3].ss=c-b;
                }
                else{
                    cnt2++;
                    y[cnt2].v=b,y[cnt2].v1=c,y[cnt2].ss=b-c;
                }
                continue;
            }
            if(b==minn){
                if(a<c){
                    cnt3++;
                    z[cnt3].v=c,z[cnt3].v1=a,z[cnt3].ss=c-a;
                }
                else{
                    cnt1++;
                    x[cnt1].v=a,x[cnt1].v1=c,x[cnt1].ss=a-c;
                }
                continue;
            }
            if(c==minn){
                if(b<a){
                    cnt1++;
                    x[cnt1].v=a,x[cnt1].v1=b,x[cnt1].ss=a-b;
                }
                else{
                    cnt2++;
                    y[cnt2].v=b,y[cnt2].v1=a,y[cnt2].ss=b-a;
                }
            }
        }
        long long maxn=max(cnt1,max(cnt2,cnt3)),ans=0;
        if(maxn<=n/2){
            for(int i=1;i<=cnt1;i++){
                ans+=x[i].v;
            }
            for(int i=1;i<=cnt2;i++){
                ans+=y[i].v;
            }
            for(int i=1;i<=cnt3;i++){
                ans+=z[i].v;
            }
            cout<<ans<<endl;
            continue;
        }
        if(cnt1==maxn){
            sort(x+1,x+1+cnt1,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=x[i].v;
            }
            for(int i=n/2+1;i<=cnt1;i++){
                ans+=x[i].v1;
            }
            for(int i=1;i<=cnt2;i++){
                ans+=y[i].v;
            }
            for(int i=1;i<=cnt3;i++){
                ans+=z[i].v;
            }
        }
        else if(cnt2==maxn){
            sort(y+1,y+1+cnt2,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=y[i].v;
            }
            for(int i=n/2+1;i<=cnt2;i++){
                ans+=y[i].v1;
            }
            for(int i=1;i<=cnt1;i++){
                ans+=x[i].v;
            }
            for(int i=1;i<=cnt3;i++){
                ans+=z[i].v;
            }
        }
        else if(cnt3==maxn){
            sort(z+1,z+1+cnt3,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=z[i].v;
            }
            for(int i=n/2+1;i<=cnt3;i++){
                ans+=z[i].v1;
            }
            for(int i=1;i<=cnt2;i++){
                ans+=y[i].v;
            }
            for(int i=1;i<=cnt1;i++){
                ans+=x[i].v;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
