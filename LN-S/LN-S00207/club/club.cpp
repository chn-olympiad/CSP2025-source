#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
int a[5][N],s[N],ans=-1;;
void dfs(int x,int y,int cnt1,int cnt2,int cnt3,int sum){

    if(cnt1>n/2||cnt2>n/2||cnt3>n/2)return;
    if(x>=n){
        ans=max(sum,ans);
        return;
    }

    if(sum+s[x]<ans)return ;
    dfs(x+1,1,cnt1+1,cnt2,cnt3,sum+a[1][x+1]);
    dfs(x+1,2,cnt1,cnt2+1,cnt3,sum+a[2][x+1]);
    dfs(x+1,3,cnt1,cnt2,cnt3+1,sum+a[3][x+1]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;bool flg=1;
        for(int i=1;i<=n;i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            if(a[2][i]||a[3][i])flg=0;
        }
        memset(s,0,sizeof s);ans=-1;
        s[n]=max({a[1][n],a[2][n],a[3][n]});
        for(int i=n-1;i>=1;i--){
            s[i]=s[i+1]+max(a[1][i],max(a[2][i],a[3][i]));
        }
        if(flg){
            sort(a[1]+1,a[1]+n+1,greater<int>());
            int sum=0;
            for(int i=1;i<=n/2;i++)sum+=a[1][i];
            cout<<sum<<'\n';
            continue;
        }
        dfs(1,1,1,0,0,a[1][1]);
        dfs(1,2,0,1,0,a[2][1]);
        dfs(1,3,0,0,1,a[3][1]);
        cout<<ans<<'\n';
    }
    return 0;
}
