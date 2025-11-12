#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5005];
long long ans;
void dfs(int x,long long sum,int ma,int num){
	if(x==n+1){
		if(num>=3 && sum>ma*2) ans++;
		return;
	}dfs(x+1,sum+a[x],max(ma,a[x]),num+1);
	dfs(x+1,sum,ma,num);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans%N;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
