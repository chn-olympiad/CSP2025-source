#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;
int n,a[N];
long long ans=0;

void dfs(int now,int Max,long long sum){
	if(now>n){
		if(sum>2*Max){
			ans++;
			ans%=998244353;
		}	
		return;
	}
	dfs(now+1,Max,sum);
	dfs(now+1,max(Max,a[now]),sum+a[now]);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}