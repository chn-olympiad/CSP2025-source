#include<bits/stdc++.h>
using namespace std;
int a[5010];
bool b[5010];
int sum=0;
int n;
void dfs(int cs,int cd,int xs,int zc) {
	if(xs>2&&cd>zc*2) {
		if(cs==n) {
			if(xs==n) {
				sum++;
				sum%=998244353;
				return;
			} else {
				return;
			}
		} else {
			sum++;
			sum%=998244353;
		}
	}
	for(int i=cs+1; i<=n; i++) {
		dfs(cs+1,cd+=a[i],xs+1,max(zc,a[i]));
		if(cs<n) {
			dfs(cs+1,cd,xs,zc);
		}
	}
}
int main() {
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	int a1;
	for(int i=1; i<=n; i++) {
		cin>>a1;
		b[a1]=1;
	}
	a1=0;
	for(int i=1; i<=5010; i++) {
		if(b[i]==1) {
			a1++;
			a[a1]=i;
		}
	}
	n=a1;
	dfs(0,0,0,0);
	cout<<sum;
	return 0;
}
