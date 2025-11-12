
#include<bits/stdc++.h>
using namespace std;

int n,m;
int a,b,cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m>>a;
	
	for(int i=2;i<=n*m;i++)
	{
		cin>>b;
		if(b>a)
			cnt++;
	}
	
	for(int i=1,j=1,k=0;i<=n and j<=m and k<=cnt;k++)
	{
		if(k==cnt)
		{
			cout<<j<<' '<<i;
			break;
		}
		if((j&1)==1)
		{
			if(i<n)
				i++;
			else
				j++;
		}
		else
		{
			if(i>1)
				i--;
			else
				j++;
		}
	}
	
	return 0;
}
