#include<bits/stdc++.h>
using namespace std;
int a[101];
int n,m,cj,cj_w;
bool cmp(int a,int b) {
	return a>b;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
		if(i==1) cj=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i]==cj) {
			cj_w=i;
			break;
		}
	}
	int lie=(cj_w+n-1)/n;
	cout<<lie<<" ";
	int num=cj_w-(lie-1)*n;
	if(lie%2==0) {
		cout<<n-num+1;
	} else {
		cout<<num;
	}
	return 0;
}
/*
还是道水题（普及-？）………………………………       不应该人人AC吗？ 
*/
