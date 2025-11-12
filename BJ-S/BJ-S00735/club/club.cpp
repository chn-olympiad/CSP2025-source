#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,ans;
int f[210][110][110][110];
struct love{
    int x,y,z;
}a[maxn];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            a[i].x=x;
            a[i].y=y;
            a[i].z=z;
        }
        for(int i=1;i<=n;i++){
            for(int c1=0;c1<=n/2;c1++){
                for(int c2=0;c2<=n/2;c2++){
                    for(int c3=0;c3<=n/2;c3++){
                        if(c1+c2+c3!=i)continue;
                        f[i][c1][c2][c3]=0;
                        if(c1!=0)f[i][c1][c2][c3]=max(f[i-1][c1-1][c2][c3]+a[i].x,f[i][c1][c2][c3]);
                        if(c2!=0)f[i][c1][c2][c3]=max(f[i-1][c1][c2-1][c3]+a[i].y,f[i][c1][c2][c3]);
                        if(c3!=0)f[i][c1][c2][c3]=max(f[i-1][c1][c2][c3-1]+a[i].z,f[i][c1][c2][c3]);
                        ans=max(ans,f[i][c1][c2][c3]);
                        //cout<<f[i][c1][c2][c3]<<' ';
                    }
                }
            }
            //cout<<'\n';
        }
        cout<<ans<<'\n';
    }

    return 0;
}
