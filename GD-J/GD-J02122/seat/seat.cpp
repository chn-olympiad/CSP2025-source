#include<iostream>
#include<algorithm>
using namespace std;
int n,m,c,r,s,k,a[10010],b[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+k+1,cmp);
	bool re=false;
	int cs=1;
	for(int i=1;i<=n;i=i)
	{
		for(int j=1;j<=m;j=j)
		{
			if(s==a[cs])
			{
				cout<<i<<" "<<j;
				return 0;
			}
			else
			{
				cs++;
			}
			if(j==m&&re==false) i++,re=true;
			else if(j==1&&re==true) i++,re=false;
			else
			{
				if(re)
				{
					j--;
				}
				else
				{
					j++;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
