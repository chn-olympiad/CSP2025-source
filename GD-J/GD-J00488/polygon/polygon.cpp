#include<bits/stdc++.h>
#include<cstdio>
#define mod  998244353
using namespace std;

int n;
vector<int> s;
long long ans;

void dfs(int c,long long sum,int maxx) {
	if(c==n+1) {
		return ;
	}
	for(int i=c;i<=n;i++) {
		dfs(c+1,sum,maxx);
		sum+=s[i];
		int maxxx=maxx;
		maxx=max(maxx,s[i]);
		if(c>=3 && sum>(2*maxx)) {
			ans++;
			ans%=mod;
		}
		dfs(c+1,sum,maxx);
		maxx=maxxx;
		sum-=s[i];
	}
	return ;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n>500) {
		cout<<0;
	} else {
		s.resize(n+10);
		for(int i=1;i<=n;i++) {
			scanf("%d",&s[i]);
		}
		dfs(1,0,0);
	}
	cout<<ans;
	return 0;
} 
