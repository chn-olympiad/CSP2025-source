#include<bits/stdc++.h>
using namespace std;

const int N=5e3+10;
const int mod=998244353;

int n;
int ans,cnt,mx=-1;
int a[N];

void dfs(int x,int mx,int sum,int dep){
	if(!dep){
		if(sum>(2*mx)){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=x+1;i<=n;i++){
		if((n-i+1)<dep)continue;
		dfs(i,max(mx,a[i]),(sum+a[i]),dep-1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		cout<<0;
		return 0;
	}
	for(int k=3;k<=n;k++){
		for(int i=1;i<=(n-k+1);i++){
			dfs(i,a[i],a[i],k-1);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}