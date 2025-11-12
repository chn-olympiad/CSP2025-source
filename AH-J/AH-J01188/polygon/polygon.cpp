#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int data[5005];
const int mod=998244353;
int ans;
void dfs(int x){
	for(int i=data[x-1]+1;i<=n;i++){
		data[x]=i;
		if(x>=3){
			int sum=0;
			for(int j=1;j<=x;j++)
				sum+=a[data[j]];
			if(sum>data[x])ans++;
		}ans%=mod;
		dfs(x+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1);
	cout<<ans;
	return 0;
}
