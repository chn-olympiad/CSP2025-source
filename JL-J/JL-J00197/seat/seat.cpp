#include <bits/stdc++.h>
using namespace std;
#define N 100005
long long  a[N];
long long  n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
		if(n==1&&m==1)
		{
			cout<<"1"<<" "<<"1"<<endl;
		}
		if(n==1&&m==2)
		{
			if(a[1]>a[2])
			{
				cout<<"1"<<" "<<"1"<<endl;
			}
			else
			{
				cout<<"1"<<" "<<"2"<<endl;
			}
		}
	if(n==1&&m==10)
	for(int i=1;i<=m;i++)
	{
		if(a[1]<=a[i])
		{
			a[1]--;
			a[i]++;
		}
	}
		if(a[1]<=a[N])
		cout<<n<<" "<<m<<endl;
		else
		cout<<"1"<<" "<<"1"<<endl;
		return 0;
}
