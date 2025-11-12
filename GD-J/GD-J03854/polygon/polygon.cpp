#include<bits/stdc++.h>
using namespace std;
unsigned long long k,s;
int n,h[100010],v[100010],a2[100010],a=-1;
inline void dfs(int x,int d,int o) {
	if(d>x) {
		long long p=0;
		for(int i=1;i<x;i++){
			p+=a2[i];
		}
		if(p>a2[x]){
			k++;
			k%=998244353;
		}
		return;
	}
	for(int i=o+1;i<=n;i++){
		if(!v[i]) {
			v[i]=1;
			a2[d]=h[i];
			dfs(x,d+1,i);
			v[i]=0;
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>h[i];
		a=max(h[i],a);
	}
	if(a==1) {
		for(int i=3; i<=n; i++) {
			k=1;
			for(int j=n-i+1; j<=n; j++) {
				k*=j;
				k%=998244353;
			}
			s+=k;
			s%=998244353;
		}
		cout<<s;
	} else {
		sort(h+1,h+1+n);
		for(int i=3; i<=n; i++) {
			dfs(i,1,0);
		}
		cout<<k;
	}
	return 0;
}
