#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		long long sum=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int b,c;
			cin>>a[i]>>b>>c;
		}
		sort(a+1,a+1+n);
		for(int i=n;i>n/2;i--)
		{
			sum+=a[i];
		}
		cout<<sum<<'\n';
	} 
	return 0;	
}
