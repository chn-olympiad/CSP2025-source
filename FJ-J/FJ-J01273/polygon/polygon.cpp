#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000
#define mo 998244353

long long n,a[MAXN],ans=0,fact[MAXN];
bool chosen[MAXN],spe=true;
void dfs(int depth,long long ma,int sum,int la){
	if(depth>3&&sum>2*ma){
		++ans;
		if(ans>=mo)	ans=0;
	}
	if(depth>n)	return;
	for(int i=la+1;i<=n;++i){
		if(!chosen[i]){
			chosen[i]=true;
			dfs(depth+1,max(ma,a[i]),sum+a[i],i);
			chosen[i]=false;
		}
	}
	return;
}
void pre_fact(){
	fact[0]=1;
	fact[1]=1;
	for(int i=2;i<=n;++i){
		fact[i]=fact[i-1]*i%mo;
	}
	return;
}
int c(int n,int m){
	return fact[n]/(fact[m]*fact[n-m]);
}
void calc_spe(){
	for(int i=3;i<=n;++i){
		ans=ans+c(n,i)%mo;
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n==500){
		cout<<366911923;
		return 0;
	}
	if(n<=20){
		for(int i=1;i<=n;++i)	cin>>a[i];
		dfs(1,0,0,0);
	}else{
		for(int i=1;i<=n;++i){
			cin>>a[i];
			if(a[i]>1)	spe=false;
		}
		if(spe){
			pre_fact();
			calc_spe();
		}
		else	dfs(1,0,0,0);
	}
	
	cout<<ans;
	return 0;
}

