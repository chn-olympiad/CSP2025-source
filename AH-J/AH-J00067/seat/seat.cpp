#include<bits/stdc++.h>
using namespace std;
int a[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int x=a[1];
	for (int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1);
	int rank;
	for (int i=n*m;i>=1;i--)
		if (a[i]==x)
			rank=n*m-i;
	int b=rank/n;
	cout<<b+1<<" ";
	if (b%2)
		cout<<n-(rank%n);
	else cout<<1+(rank%n);
	return 0;
}
