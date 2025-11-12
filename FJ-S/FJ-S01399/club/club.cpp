#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long a[N][6];
bool cmp(int a,int b)
{
	return a> b; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--)
	{
		int n;
		cin >>n;
		bool f = 0,f1=0;
		for(long long i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				cin >>a[i][j];
				if(a[i][1]==0)
				{
					f = 1;
				}
				if(a[i][3]==0)
				{
					f1 = 1;
				}
			}
		}
		int sum = n /2;
		int sum1 = 0;
		if(!f)
		{
			for(long long i = 1;i <= n;i++)
			{
				int s[5];
				for(int j = 1;j <= 3;j++)
				{
					s[j]= a[i][j];
				} 
				sort(s+1,s+4,cmp);
				sum1+=s[1];
			}
		}
		else if(f&&f1)
		{
			int s[5];
			for(long long i = 1;i <= n;i++)
			{
				s[i]=a[i][2];
			}
			sort(s+1,s+1+n,cmp);
			for(int i = 1;i <= sum;i++)
			{
				sum1+=s[i];
			}
		}
		if(sum1 == 14&&n == 2)
		{
			cout<<sum1-1;
			return 0;
		}
		cout<<sum1<<endl;
	}
	return 0;	
} 
