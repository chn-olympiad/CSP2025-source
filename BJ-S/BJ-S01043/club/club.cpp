#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005];
int tmp[15];
int ca[100005],cb[100005],cc[100005],cd[100005],mxt[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        memset(tmp,0,sizeof(tmp));
        memset(cd,0x3f,sizeof(cd));
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            int mx=max(a[i],max(b[i],c[i]));
            if(mx==a[i])tmp[1]++,ca[i]=0,cb[i]=a[i]-b[i],cc[i]=a[i]-c[i],ans+=a[i],mxt[i]=1;
            else if(mx==b[i])tmp[2]++,ca[i]=b[i]-a[i],cb[i]=0,cc[i]=b[i]-c[i],ans+=b[i],mxt[i]=2;
            else tmp[3]++,ca[i]=c[i]-a[i],cb[i]=c[i]-b[i],cc[i]=0,ans+=c[i],mxt[i]=3;
        }
        if(tmp[1]<=n/2&&tmp[2]<=n/2&&tmp[3]<=n/2){
            cout<<ans<<endl;//不超过直接输出
        }else{
            int tcnt=0;
            if(tmp[1]>n/2){
                for(int i=1;i<=n;i++){
                    if(mxt[i]==1)cd[++tcnt]=min(cb[i],cc[i]);
                }
                sort(cd+1,cd+tcnt+1);
                for(int i=1;i<=tmp[1]-n/2;i++)ans-=cd[i];
                cout<<ans<<endl;
            }
            else if(tmp[2]>n/2){
                for(int i=1;i<=n;i++){
                    if(mxt[i]==2)cd[++tcnt]=min(ca[i],cc[i]);
                }
                sort(cd+1,cd+tcnt+1);
                for(int i=1;i<=tmp[2]-n/2;i++)ans-=cd[i];
                cout<<ans<<endl;
            }
            else if(tmp[3]>n/2){
                for(int i=1;i<=n;i++){
                    if(mxt[i]==3)cd[++tcnt]=min(cb[i],ca[i]);
                }
                sort(cd+1,cd+tcnt+1);
                for(int i=1;i<=tmp[3]-n/2;i++)ans-=cd[i];
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
