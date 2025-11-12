#include<iostream>
#include<cstdio>
using namespace std;
int jc(int m,int n) {
	int mj=1,nj=1,mnj=1;
	for(int i=2; i<=m; i++) {
		mj*=i;
	}
	for(int i=2; i<=n; i++) {
		nj*=i;
	}
	for(int i=2; i<=m-n; i++) {
		mnj*=i;
	}
	return mj/nj/mnj;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n, sum=0;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	for(int i=3; i<=n; i++) {
		sum+=jc(n,i);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}