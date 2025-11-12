#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5090];
int b[5090];
long long sum;
void dfs(int t,int cnt,int maxn,int k){
    if(t==n+1){
        if(cnt>maxn*2&&k>=3){
            sum=(sum+1)%998244353;
        }
        return;
    }
    dfs(t+1,cnt+a[t],max(a[t],maxn),k+1);
    dfs(t+1,cnt,maxn,k);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-2;i++){
        dfs(i+1,a[i],a[i],1);
    }
    cout<<sum%998244353;
	return 0;
}
