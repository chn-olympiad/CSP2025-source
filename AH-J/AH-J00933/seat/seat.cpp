#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],mp[15][15],my;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	my=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{	
			if(j%2==1)mp[i][j]=(j-1)*m+i;
			else mp[i][j]=2*m-i+1;
			mp[i][j]=a[mp[i][j]];
			if(mp[i][j]==my)
			{
				printf("%d %d\n",j,i);
				//break;
			}
		}
	//for(int i=1;i<=n;i++)
		//for(int j=1;j<=m;j++)cout<<mp[i][j]<<(j<n?" ":"\n");
	return 0;
}
/*
2 2
99 100 97 98
 */
