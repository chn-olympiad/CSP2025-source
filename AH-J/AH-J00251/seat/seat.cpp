#include<bits/stdc++.h>
using namespace std;
int n,m,b[10005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>b[i];
	int p=b[1];
	sort(b+1,b+n*m,cmp);
	int i=0,id=0;
	while(1)
	{
		i++;
		if(i%2==1)
			for(int j=1;j<=n;j++)
			{
				id++;
				if(b[id]==p)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		else
			for(int j=n;j>=1;j--)
			{
				id++;
				if(b[id]==p)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
	}
	return 0;
}




