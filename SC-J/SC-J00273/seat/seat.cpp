#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) cin>>a[i];
	int t=a[1],pos;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i]==t) pos=i;
	}
//	cout<<pos<<endl;
	int lie,hang;
	if(pos%n==0) lie=pos/n;
	else lie=pos/n+1;

	int k=pos%n;
	if(lie%2==1) {
		hang=k;
		if(k==0) {
			hang=n;
		}
	} else {
		hang=n-k+1;
		if(k==0) {
			hang=1;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
/*
2 2
99 100 97 98

3 3
94 95 96 97 98 99 100 93 92

*/