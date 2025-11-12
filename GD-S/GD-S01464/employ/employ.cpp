#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+5,mod=998244353;
ll n,m,c[N],f[N],p[N],sum,ff[N],ch[N],flag;
string ss;
void dfs(ll x) {
	if(x==n+1) {
		ch[0]=0;
		for(int i=1;i<=n;i++) {
			if(f[i]==0||ch[i-1]>=p[i]) {
				ch[i]=ch[i-1]+1;
			} else {
				ch[i]=ch[i-1];
			}
		}
		if(ch[n]<=n-m) {
			sum++;
		}
		return;
	}
	for(int i=1;i<=n;i++) {
		if(!ff[i]) {
			p[x]=c[i];
			ff[i]=1;
			dfs(x+1);
			ff[i]=0;
		}
	}
	return;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>ss;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	for(int i=0;i<n;i++) {
		f[i+1]=ss[i]-'0';
	}
	if(n<=10) {
		dfs(1);
		cout<<sum;
	} else if(m==n) {
		for(int i=1;i<=n;i++) {
			if(!f[i]) {
				flag=1;
			}
			if(!c[i]) {
				flag=1;
			}
		}
		if(flag) {
			cout<<0;
		} else {
			sum=1;
			for(int i=1;i<=n;i++) {
				sum=sum*i%mod;
			}
			cout<<sum;
		}
	}
	return 0;
} 
