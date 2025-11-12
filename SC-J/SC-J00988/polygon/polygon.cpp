#include<bits/stdc++.h>
using namespace std;
int n,p=0,mmax,b[5001],c=0,a[5500],jj[5500];
void f(int in,int m) {
	if(m==in) {
		for(int i=0; i<in; i++) {
			c+=b[i];
			if(mmax<b[i]) {
				mmax=b[i];
			}
		}
		if(c>=2*mmax) {
			p++;
			p%=998244353;
			return;
		}
		return;
	}
	for(int j=1; j<=n; j++) {
		if(jj[j]!=0) {

		} else {
			b[m]=a[j];
			jj[j]=1;
			f(in,m+1);
			jj[j]=0;
			m=0;
			mmax=-999;
		}
	}
	return;
}
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	memset(jj,0,sizeof(jj));
	for(int i=3; i<=n; i++) {
		f(i,0);
	}
	cout<<p;
	return 0;
}