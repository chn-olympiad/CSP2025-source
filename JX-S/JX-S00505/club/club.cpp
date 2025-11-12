#include<bits/stdc++.h>
using namespace std;
int const N=2e5+10;
int a[N][5];
int t,n;
int x[N],y[N],z[N];
int o[N][5];
int ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int p=0;
        int f=0;
        ans=0;
        for(int i=1;i<=N;i++){
                x[i]=0;
                y[i]=0;
                z[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i]>>z[i];
        }
        sort(x+1,x+n+1);
        sort(y+1,y+n+1);
        sort(z+1,z+n+1);
        int flag1=0;
        int flag2=0;
        int flag3=0;
        for(int i=n;i>=1;i--){
            int maxn=max(x[i],max(y[i],z[i]));
            if(maxn==x[i]&&flag1<=n/2){
                ans+=maxn;
                flag1++;
                continue;
            }
            if(maxn==y[i]&&flag2<n/2){
                ans+=maxn;
                flag2++;
                continue;
            }
             if(maxn==z[i]&&flag3<n/2){
                ans+=maxn;
                flag3++;
                continue;
            }
        }
        cout<<ans<<endl;
    }
}
