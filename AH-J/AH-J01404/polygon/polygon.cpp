#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FRR freopen("polygon.in","r",stdin)
#define FRW freopen("polygon.out","w",stdout)
const int MOD=998244353;
int a[5010];
int n;
int dfs(int x,int s,int m,int c){
    if(x>n) return (s>m*2&&c>=3 ? 1 : 0);
    int cnt=dfs(x+1,s,m,c)+dfs(x+1,s+a[x],max(m,a[x]),c+1);
    cnt%=MOD;
    return cnt;
}
signed main(){
    FRR;
    FRW;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<dfs(1,0,0,0);
	return 0;
}
