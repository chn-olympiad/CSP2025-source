#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==num)
		{
			int j=n*m-i+1;
			int hang,lie;
			if(int(ceil(double(j)/double(n)))%2==0)
			{
				if(j%n==0)
				hang=1;
				else
				hang=n-(j%n)+1;
			}
			else{
				if(j%n==0)
				hang=n;
				else
				hang=j%n;
			}
			lie=ceil(double(j)/double(n));
			cout<<lie<<' '<<hang;
			return 0;
		}
	}
	return 0;
}
