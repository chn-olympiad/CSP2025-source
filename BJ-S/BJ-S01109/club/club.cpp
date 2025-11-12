#include<bits/stdc++.h>
using namespace std;
int a[100010][10];
int ans,n;
void dfs(int x,int y,int z,int w,int p) {
    if(x>n) {
        ans=max(ans,p);
        return ;
    }
    if(y<n/2) {
        dfs(x+1,y+1,z,w,p+a[x][1]);
    }
    if(z<n/2) {
        dfs(x+1,y,z+1,w,p+a[x][2]);
    }
    if(w<n/2) {
        dfs(x+1,y,z,w+1,p+a[x][3]);
    }
    return ;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        ans=0;
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
