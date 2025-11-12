#include<bits/stdc++.h>
using namespace std;
struct nssl{
	int s,m,p;
}a[100001];
bool tmp(nssl x,nssl y)
{
	return x.s>y.s;
}
int T,n; 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie();
	cout.tie();
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].s>>a[i].m>>a[i].p;
		}
		sort(a+1,a+n+1,tmp);
		int sum=0;
		for(int i=1;i<=n/2;i++)
		{
			sum+=a[i].s;
		}
		cout<<sum<<'\n';
	}
	
	return 0;
}
