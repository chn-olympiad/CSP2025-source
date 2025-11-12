#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
const int mod=998244353;
int n;
int a[N];
int ans;
int vis[N];
int dfs(int p,int l,int sum,int m){
	int anss=0;
	if(l==0){
		if(sum>2*m){
			return 1;
		}
		else{
			return 0;
		}
	}
	vis[p]=1;
	sum+=a[p];
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			anss+=dfs(a[i],l-1,sum,max(m,a[i]));
		}
	}
	vis[p]=0;
	return anss; 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int p=2,i=3;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			sum+=dfs(a[j],i-1,0,a[j]);
		}
		sum/=p;
		p=p*i;
		ans+=sum;
	}
	cout<<ans;
	return 0;
}
