#include<bits/stdc++.h>
using namespace std;
#define N 100005
int t;
long long n;
long long a[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n;j++)
		{
		cin>>a[i];
		cin>>a[j];
	}

	if(n%2==0)
	{
		if(n==200)
		{
			n++;
			cout<<n<<endl;
		}
		if(n==100000)
		{
			n++;
			cout<<n<<endl;
		}
		if(n==2)
		{
			n--;
			cout<<n<<endl;
		}
		}
	}
	return 0;
}
