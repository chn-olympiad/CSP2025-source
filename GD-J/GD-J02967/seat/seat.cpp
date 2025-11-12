#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct stu
{
	long long s;
	bool is;
}a[110];

long long n,m;

bool cmp(stu a,stu b)
{
	return a.s>b.s;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)cin>>a[i].s;
	a[1].is=1;
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1,cnt=0;i<=n;i++)
	{
		if(i&1)for(long long j=1;j<=m;j++)
		{
			cnt++;
			if(a[cnt].is)
			{
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
		else for(long long j=m;j>=1;j--)
		{
			cnt++;
			if(a[cnt].is)
			{
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
}
/*
3 3
94 95 96 97 98 99 100 93 92

2 2
99 100 97 98

2 2
98 99 100 97


3 3
94 95 96 97 98 99 100 93 92
*/ 
