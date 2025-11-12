#include<bits/stdc++.h>
using namespace std;
int a[5010];
int sum=0,cnt;
void dfs(int u,int k,int maxx){
	if(k==0){
		if(sum>maxx*2){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	for(int i=k;i<u;i++){
		sum+=a[i];
		dfs(i,k-1,max(maxx,a[i]));
		sum-=a[i];
	}
}
int main(){
	freopen("E:GD-J01259/polygon/polygon.in","r",stdin);
	freopen("E:GD-J01259/polygon/polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(n+1,i,0);
	}
	cout<<cnt;
}
