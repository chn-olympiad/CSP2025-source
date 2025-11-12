#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
void dfs(int c,int k,int sum,int maxn){
    if(k>=3&&sum>2*maxn){
        ans++;
        ans=ans%998244353;
    }
    for(int i=c+1;i<=n;i++){
        dfs(i,k+1,sum+a[i],max(a[i],maxn));
    }
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        dfs(i,1,a[i],a[i]);
	}
	cout<<ans;
	return 0;
}
