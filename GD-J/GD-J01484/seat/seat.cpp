#include<bits/stdc++.h>
using namespace std;
int a[410],b[410],x[410],y[410];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ran;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ran=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=n*m,j=1;i>=1;i--,j++){
		b[j]=a[i];
	}
	int cur=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=n;j++)
			{
				cur++;
				x[cur]=i;
				y[cur]=j;
				
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				cur++;
				x[cur]=i;
				y[cur]=j;
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]==ran)
		{
			cout<<x[i]<<' '<<y[i]<<endl;
			return 0;
		}
	}
}
