#include<bits/stdc++.h>
using namespace std;
int a[1009];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,i;
	cin>>n>>m;
	cin>>a[1];
	int k=a[1],p;
	for(i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,greater<int>());
	for(i=1;i<=n*m;i++)
		if(a[i]==k)
		{
			p=i;
			break;
		}
	if(p%n==0)
		cout<<(p/n)<<' ';
	else
		cout<<(p/n)+1<<' ';
	if(p%(2*n)<=n)
		cout<<p%n;
	else
		cout<<n-(p%n)+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
