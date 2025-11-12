#include <bits/stdc++.h>
#define int long long
using namespace std;
int cc[100005][4];
int n,x,y,z;
int ans=0;
void dfs(int a,int b,int c){
    if(a+b+c==n+1)return;
    if(a+1<=n/2)x=dfs(a+1,b,c)+cc[a+b+c][1];
    if(b+1<=n/2)y=dfs(a,b+1,c)+cc[a+b+c][1];
    if(c+1<=n/2)z=dfs(a,b,c+1)+cc[a+b+c][1];
    ans=max(x,max(y,z));
}
signed main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>cc[i][j];
            }
        }
        dfs(0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
                                        
