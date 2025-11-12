#include <bits/stdc++.h>
using namespace std;
int n,m,num,a[102];
int sum;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	sum=1;
	for (int i=1;i<=n;i++)
	{
		if (i%2==1)
        {
        	for(int j=1;j<=m;j++)
        	{
        		if (a[sum]==num)
        		{
        			cout<<i<<" "<<j;
        			return 0;
			    }
			    sum++;
			}
		}
		else{
			for (int j=1;j<=m;j++)
	        {
				if (a[sum]==num)
				{
					cout<<i<<" "<<m-j+1;
					return 0;
				}
				sum++;
			}
		}
	}
	return 0;
}

