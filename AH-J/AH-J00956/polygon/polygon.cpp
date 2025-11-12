#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005],n,ans;
void dfs(int si,int k,int sum){
	if(si>n)return;
	if(sum+a[si]>a[si]*2&&k>=2){
		ans++;
        ans%=mod;
	}
    dfs(si+1,k+1,sum+a[si]);
    dfs(si+1,k,sum);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
