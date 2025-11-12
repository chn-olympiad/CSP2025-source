#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=5010;
int l[N],n,ans;
bool right(int m,int rl[]) {
	if(m<3) return false;
	int mmax=-1,all=0;
	for(int i=1;i<=m;i++) {
		mmax=max(mmax,rl[i]);
		all+=rl[i];
	}
	if(all>2*mmax) {
		return true;
	}
	return false;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&l[i]);
	}
	if(right(n,l)) {
		cout<<1<<endl;
	}
	else cout<<0<<endl;
	return 0;
}