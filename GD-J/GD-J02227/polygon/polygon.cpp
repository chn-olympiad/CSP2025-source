#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mod=998244353;

int n;
int a[5005];
int ans;
int vis[5005];

void dfs(int he,int mx,int sum,int xuan){
	if(2*mx<he&&sum>=3){
		ans++;
		ans%=mod;
	}
	if(sum>n)
		return;
	for(int i=xuan;i<=n;i++){
		if(vis[i])
			continue;
		mx=max(mx,a[i]);
		vis[i]=1;
		sum++;
		dfs(he+a[i],mx,sum,i);
		vis[i]=0;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	dfs(0,0,0,1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
