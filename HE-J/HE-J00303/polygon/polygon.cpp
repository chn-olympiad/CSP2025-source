#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>inline void read(T&x) {
	x=0;
	char c;
	int sgin=1;
	do {
		c=getchar();
		if(c=='-')sgin=-1;
	} while(!isdigit(c));
	do {
		x=(x<<3)+(x<<1)+(c&15);
		c=getchar();
	} while(isdigit(c));
	x*=sgin;
}
const int mod=998244353;
int n,l[5010],ans;
bool vis[5010];

int qpow(int a,int b){
	if(b==0)return 1;
	int res=1;
	while(b!=0){
		if(b&1)res=res%mod*a%mod;
		a=a%mod*a%mod;
		b>>=1;
	}
	return res;
}

void dfs(int total,int maxn,int cnt,int top){
	if(cnt>=3&&total>maxn*2)ans++;
	for(int i=top+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(total+l[i],max(maxn,l[i]),cnt+1,i);
			vis[i]=false;
		}
	}
}

signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	bool flag=true;
	for(int i=1;i<=n;i++){
		read(l[i]);
		if(i!=1&&l[i]!=l[i-1]){
			flag=false;
		}
	}
	if(flag){
		cout<<qpow(2,(n-3)*2);
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans%mod;
	return 0;
}
/*
3 1 2^0
4 4 2^2
5 16 2^4
*/
