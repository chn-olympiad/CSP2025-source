#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[110],cnt;
	int r,sum=1;
	cin>>n>>m;
	if(n==1&&m==1)
	{
		cout<<"1 1";
		return 0;
	}
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		cnt++;
	}
    r=a[0];
	sort(a-1,a+n*m-1,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==r)
		{
			break;
		}
		sum++;
	}
	if(r==100)
	{
		cout<<"1 1";
		return 0;
	}
	if(n==1)
	{
		cout<<sum<<" "<<"1";
		return 0;
	}
	if(m==1)
	{
		cout<<"1"<<" "<<sum;
		return 0;
	}
	return 0;
}

