#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15;
int a[N*N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int d=a[1];
	sort(a+1,a+1+n*m);
	int idx=n*m-(lower_bound(a+1,a+1+n*m,d)-a)+1;
	int c=ceil(1.0*idx/n),r=idx%n;
	if(r==0)
		r=n;
	if(!(c&1))
		r=n+1-r;
	cout<<c<<' '<<r<<'\n';
	return 0;
}