#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,s,l,q,w;
int a[2100000];
bool cmp(int a,int b) {
	return a>b;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i]==s) {
			l=i;
		}
	}
	q=l%n;
	w=l/n;
	if(w*n!=l){
		w++;
	}
	if(q==0){
		q=n;
	}
	if(w%2==0){
		cout<<w<<" "<<n-q+1;
	}else{
		cout<<w<<" "<<q;
	}
	return 0;
}
/*
4 4
11 1 2 3 4 5 6 7 8 9 10 12 13 14 15 16
*/
