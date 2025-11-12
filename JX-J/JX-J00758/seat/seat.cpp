#include<bits/stdc++.h>
using namespace std;
int a[103],n,m,o,s,b[13][13],cnt=1;
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=n*m;
	for(int i=1;i<=p;i++)
	{
		cin>>a[i];
		if(i==1) o=a[i];
	}
	sort(a+1,a+p+1,cmp);
	for(int i=1;i<=n;)
	{
		for(int j=1;j<=m;)
		{
			b[i][j]=a[cnt];
			cnt++;
			if(o==b[i][j])
			{
				cout<<j<<" "<<i;
				return 0;
			}
			if(j%2==0)
			{
				if(i != 1)
				{
					i--;
					continue;
				}
				else j++;
			}
			else
			{
				if(i != n)
				{
					i++;
					continue;
				}
				else j++;
			}
		}
	}	
	return 0;
}
