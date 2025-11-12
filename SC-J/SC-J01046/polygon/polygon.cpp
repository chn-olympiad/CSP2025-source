#include<bits/stdc++.h>
using namespace std;
#define N 50005
#define int long long

int ans;
int n,mod=998244353;
int a[N],vi[25000000];

void dfs(int id,int bian,int maxx,int sum,int vis){
	if(vi[vis])	return ;
	if(bian>=3&&maxx*2<sum&&!vi[vis]){
		vi[vis]=1;
//		cout<<vis<<" ";
		ans++;
		ans%=mod;
	}
	if(id>n){
		return ;
	}
	for(int i=id;i<=n;i++){
		int maxc=max(maxx,a[i]),sc=sum+a[i];
//		cout<<vis<<" "<<id<<" "<<i<<" "<<vis+(1<<(i-1))<<endl;
		dfs(i+1,bian+1,maxc,sc,vis+(1<<(i-1)));
		dfs(i+1,bian,maxx,sum,vis);
	}
}

int C(int a,int b){
	int ans=1;
	for(int i=b+1;i<=a;i++){
		ans*=i;
//		ans%=mod;
	}
	for(int i=1;i<=a-b;i++){
//		if(ans<=i)	cout<<i<<" ";
		ans/=i;
	}
	return ans;
}
 
int maxx=0;

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx<=1){
		for(int i=3;i<=n;i++){
			ans+=C(n,i);
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0,0);
	cout<<ans;
	return 0;  
} 

/*
20 
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

5 
1 2 3 4 5
*/