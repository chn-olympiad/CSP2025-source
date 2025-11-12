#include<bits/stdc++.h>
using namespace std;
int n,f=0;
long long ans=0;
int a[5005],s[5005];

void dfs(int i,int t,int sum,int maxl){
	if(i>n){
		if(sum>2*maxl){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	s[++t]=i;
	dfs(i+1,t,sum+a[i],a[i]);
	--t;
	dfs(i+1,t,sum,maxl);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			f++;
		}
	}
	
	if(f==n){//È«ÊÇ1 
		int x=2;
		int y=n*(n-1);
		for(int i=3;i<=n;i++){
			x*=i;
			y*=n-i+1;
			ans+=y/x%998244353;
		}
		cout<<ans<<"\n";
		return 0;
	}
	
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans%998244353<<"\n";
	return 0;
}
