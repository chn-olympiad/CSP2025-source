#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100005];
int t;
int maxx=-1e18;
const int mod=998244353;
void dfs(int x,int ans,int f,int cnt){
	if(x==n+1){
		if(ans>2*f&&cnt>=3){
			t++;
			t%=mod;
		}
		return;
	}
	dfs(x+1,ans+a[x],max(f,a[x]),cnt+1);
	dfs(x+1,ans,f,cnt);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){
		int k=n*(n-1)/2;
		k+=n;
		k++;
		int h=1;
		for(int i=1;i<=n;i++){
			h*=2;
			h%=mod;
		}
		h-=k;
		h%=mod;
		h=(h+mod)%mod;
		cout<<h;
	}
	else{
		dfs(1,0,0,0);
		t%=mod;
		cout<<t;
	}
	return 0;
}
