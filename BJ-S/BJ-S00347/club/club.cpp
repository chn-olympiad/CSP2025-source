#include<bits/stdc++.h>
using namespace std;
int a[100010][4];
int ans;
int a1,a2,a3;
int n;
void dfs(int x,int cnt){
    if(a1>n/2||a2>n/2||a3>n/2) return ;
    if(x>n){
        ans=max(cnt,ans);
        return ;
    }
    a1++;
    dfs(x+1,cnt+a[x][1]);
    a1--;
    a2++;
    dfs(x+1,cnt+a[x][2]);
    a2--;
    a3++;
    dfs(x+1,cnt+a[x][3]);
    a3--;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
