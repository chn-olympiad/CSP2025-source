#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],num,t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	num=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		t=n*m-i+1;
		if(a[i]==num)
			break;
	}
	cout<<(t+n-1)/n<<" ";
	if(((t+n-1)/n)%2==1)
		cout<<(t-1)%n+1;
	else
		cout<<n-(t-1)%n;
	return 0;
}