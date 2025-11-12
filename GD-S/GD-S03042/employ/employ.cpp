#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[600];
int c[600];
bool pd=1;
long long ans;
long long jc[600];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	jc[1]=1;
	for(int i=2; i<=n+1; i++) {
		jc[i]=jc[i-1]*i;
		jc[i]%=998244353;
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	int l=strlen(a);
	for(int i=0; i<l; i++) {
		if(a[i]=='0') {
			pd=0;
			break;
		}
	}
	if(pd) {
		int sum=0;
		for(int i=1; i<=n; i++) {
			if(c[i]==0) {
				sum++;
			}
		}
		cout<<jc[n];
	}
	return 0;
}
