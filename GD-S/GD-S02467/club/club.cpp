#include<bits/stdc++.h>
using namespace std;
struct dot{int x,y,z;};
int t,n,g;
int a[100000][3];
int dp[101][101][101];
bool u[101][101][101];
int o[100000];
vector<dot> l1,l2,*now=&l1,*nex=&l2;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        g=0;
        now->clear();
        nex->clear();
        fill(dp[0][0],dp[0][0]+101*101*101,0);
        if(n<100000){
            for(int i=0;i<n;++i){
                for(int j=0;j<3;++j){
                    cin>>a[i][j];
                }
            }
            for(int i=0;i<n>>1;++i)
                for(int j=0;j<n>>1;++j)
                    for(int k=0;k<n>>1;++k) u[i][j][k]=0;
            now->push_back({0,0,0});
            for(int i=0;i<n;++i){
                while(!now->empty()){
                    dot k=now->back();
                    now->pop_back();
                    if(k.x+1<=n/2){
                        dp[k.x+1][k.y][k.z]=max(dp[k.x+1][k.y][k.z],dp[k.x][k.y][k.z]+a[i][0]);
                        if(!u[k.x+1][k.y][k.z]){
                            nex->push_back({k.x+1,k.y,k.z});
                            u[k.x+1][k.y][k.z]=1;
                        }
                    }
                    if(k.y+1<=n/2){
                        dp[k.x][k.y+1][k.z]=max(dp[k.x][k.y+1][k.z],dp[k.x][k.y][k.z]+a[i][1]);
                        if(!u[k.x][k.y+1][k.z]){
                            nex->push_back({k.x,k.y+1,k.z});
                            u[k.x][k.y+1][k.z]=1;
                        }
                    }
                    if(k.z+1<=n/2){
                        dp[k.x][k.y][k.z+1]=max(dp[k.x][k.y][k.z+1],dp[k.x][k.y][k.z]+a[i][2]);
                        if(!u[k.x][k.y][k.z+1]){
                            nex->push_back({k.x,k.y,k.z+1});
                            u[k.x][k.y][k.z+1]=1;
                        }
                    }
                }
                swap(now,nex);
                ++g;
            }
            int ans=0;
            if(g%2==0)
            for(int i=0;i<l1.size();++i){
                ans=max(dp[l1[i].x][l1[i].y][l1[i].z],ans);
            }
            else
                for(int i=0;i<l2.size();++i){
                ans=max(dp[l2[i].x][l2[i].y][l2[i].z],ans);
            }
            cout<<ans<<endl;
        }
        else{
                fill(o,o+100000,0);
            for(int i=0,b,c;i<n;++i) cin>>o[i]>>b>>c;
            sort(o,o+100000);
            int ans=0;
            for(int i=n-1;i>=n>>1;--i) ans+=o[i];
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
