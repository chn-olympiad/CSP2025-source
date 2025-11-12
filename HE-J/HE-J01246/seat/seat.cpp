#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200],num=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1]) num++;
	}
	if(num%n==0)
	{
		cout<<num/n<<" ";
		if((num/n)%2==1) cout<<n;
		else cout<<1;
	}
	else
	{
		cout<<num/n+1<<" ";
		if((num/n+1)%2==1) cout<<num%n;
		else cout<<n-num%n+1;
	}
	return 0;
}
