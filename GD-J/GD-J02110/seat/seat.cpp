#include<bits/stdc++.h>
using namespace std;
int n,m,p,s,a[101];
int main()
{
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<n*m;i++) cin>>a[i];
	sort(a+1,a+n*m,greater<int>());
	p=upper_bound(a+1,a+n*m-1,s,greater<int>())-a;
	cout<<(p-1)/n+1<<' ';
	if(((p-1)/n)&1) cout<<n-(p-1)%n;
	else cout<<(p-1)%n+1;
}
