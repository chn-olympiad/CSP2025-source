#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],vis[5005],ans[5005],cnt=1,sum=0,maxn[5055];
bool check(long long l){
	return sum>maxn[l]*2; 
}
void dfs(int cur){
	if(check(cur-1)&&cur-1>=3) cnt++;
	if(cur>n) return ;
	for(int i=cur+1;i<=n;i++){
		if(!vis[i]){
			sum+=a[i];
			maxn[cur]=max(maxn[cur-1],a[i]);
			vis[i]=1;
			ans[cur]=a[i];
			dfs(cur+1);
			vis[i]=0;
			sum-=a[i];
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<cnt;
	return 0;
}
