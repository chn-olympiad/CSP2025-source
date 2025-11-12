#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,s1[N],s2[N],s3[N];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int cnt1=0,cnt2=0,cnt3=0,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y,z,c=0;cin>>x>>y>>z;
            if(x>y&&x>z){
                if(y>z) c=x-y;
                else c=x-z;
                ans+=x;
                s1[++cnt1]=c;
            }else if(y>x&&y>z){
                if(x>z) c=y-x;
                else c=y-z;
                ans+=y;
                s2[++cnt2]=c;
            }else if(z>x&&z>y){
                if(x>y) c=z-x;
                else c=z-y;
                ans+=z;
                s3[++cnt3]=c;
            }else if(x==y){
                ans+=x;
                s1[++cnt1]=0;
            }else if(y==z){
                ans+=y;
                s2[++cnt2]=0;
            }else if(x==z){
                ans+=z;
                s3[++cnt3]=0;
            }
        }if(cnt1>n/2){
            sort(s1+1,s1+1+cnt1);
            int i=0;
            while(cnt1-i>n/2) ans-=s1[++i];
        }if(cnt2>n/2){
            sort(s2+1,s2+1+cnt2);
            int i=0;
            while(cnt2-i>n/2) ans-=s2[++i];
        }if(cnt3>n/2){
            sort(s3+1,s3+1+cnt3);
            int i=0;
            while(cnt3-i>n/2) ans-=s3[++i];
        }cout<<ans<<"\n";
    }return 0;
}