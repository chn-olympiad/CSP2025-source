#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int w = 1,s = 0;
	char ch = getchar();
	while(ch<48||ch>57){
		if(ch=='-')w = -1;
		ch = getchar();
	}
	while(ch>=48&&ch<=57){
		s = (s<<1)+(s<<3)+(ch^48);
		ch = getchar();
	}
	return w*s;
}

const int N = 5010,mod = 998244353;

int n,a[N],b[N],cnt = 0;
void dfs(int step){
	if(step==n+1){
		int sum = 0,maxn = 0;
		for(int i = 1;i <= n;++i){
			if(b[i])sum += a[i],maxn = max(maxn,a[i]);
		}
		if(sum>2*maxn)cnt++;
		cnt %= mod;
		return;
	}
	for(int i = 0;i <= 1;++i){
		b[step] = i;
		dfs(step+1);
		b[step] = -1;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n = read();
	memset(b,-1,sizeof(b));
	for(int i = 1;i <= n;++i)a[i] = read();
	dfs(1);
	cout<<cnt%mod;
	return 0;
}