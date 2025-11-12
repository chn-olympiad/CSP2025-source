#include<bits/stdc++.h>
using namespace std;
int n,m,e[101],l,s,ans1,ans2;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n*m; i++) {
		cin>>e[i];
		if(i==0) {
			s=e[i];
		}
	}
	sort(e,e+n*m,cmp);
	for(int i=0; i<n*m; i++) {
		if(e[i]==s) l=i+1;
	}
	if(l%n!=0) ans1=int(l/n)+1;
	else ans1=l/n;
	cout<<ans1<<" ";
	if(ans1%2) cout<<l%n;
	else cout<<n-(l%n)+1;
	return 0;
}
