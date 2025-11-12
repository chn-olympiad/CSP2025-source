#include <bits/stdc++.h>

using namespace std;
const int N=1e4+10;
int n;
int a[N];
int cntl,xc;
void dfs(int x,int ma,int l,int s) {
	l++;
	if(x>ma*2&&l>=3&&x>0) {
		xc++;
		return;
	}
	for(int i=s; i<=n; i++) {
		
		x+=a[i];
		ma=max(ma,a[i]);
		dfs(x,ma,l,i+1);
	}
	
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(0,0,0,1);
	cout<<xc/2%998244353;
	return 0;
}
