#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105]={0};
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[cnt++];
		}
	}
	sort(a+1,a+cnt,cmp);
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cnt++;
			if(a[0]>a[cnt])
			{
				if(i%2==0)
				{
					cout<<i<<" "<<n-j+1<<endl;
				}
				else
				{
					cout<<i<<" "<<j<<endl;
				}
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	return 0;
}
