#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
void dfs(long long sum,int maxi){
	for(int i=maxi+1;i<=n;i++)if(sum>a[i]){
		ans++;
		dfs(sum+a[i],i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)dfs(a[i]+a[j],j);
	cout<<ans<<endl;
	return 0;
}
