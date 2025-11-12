#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+(n*m)+1);
	int cnt=n*m,s[11][11]={};
	for(int i=1;i<=m;i++)
	{
		
		for(int j=1;j<=n;j++)
		{
			s[j][i]=a[cnt];
			cnt--;
			if(s[j][i]==r)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		for(int j=n;j>=1;j--)
		{
			s[j][i]=a[cnt];
			cnt--;
			if(s[j][i]==r)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}

	return 0;
}
