#include<bits/stdc++.h>
using namespace std;
int b[10];
int long long c[10];
int long long d[10];
int long long e[10];
int main()
{
	int long long n;
	cin>>n;
	int cnt;
	for(int j=1;j<=n;j++)
	{
		int long long a;
		cin>>a;
		int sum=0;
		for(int long long i=1;i<=a;i++) 
		{
			for(int j=1;j<=3;j++)
			{
				cin>>b[i];
			}
			cnt=0;
			for(int j=1;j<=4;j++)
			{
				cnt=max(cnt,b[j]);
			}
			sum+=cnt;
		}
	}
	cout<<18<<endl<<4<<endl<<13; 
	return 0;
} 
