#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int cmp(int a,int b){
	return a>b;
}
const int N=1e7+10;
int a[N],n,m,ming;
int main() {

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll cnt=1;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	cout<<n+4;
	return 0;
}
