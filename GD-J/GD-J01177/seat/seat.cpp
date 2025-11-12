#include<bits/stdc++.h>
using namespace std;
int f[205];
signed main()
{
	freopen("seat.in.txt","r",stdin);
	freopen("seat.out.txt","w",stdout);

	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>f[i];
	int fill[15][15],index=1,temp=f[1];
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
			for(int j=1;j<=m;j++)
			{
				fill[j][i]=index;
				index++;
			}
		else
			for(int j=m;j>=1;j--)
			{
				fill[j][i]=index;
				index++;
			}
	}
	sort(f+1,f+1+n*m,greater<int>());
	int ans=0;
	for(int i=1;i<=n*m;i++)
		if(temp==f[i]) ans=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ans==fill[i][j])
			{
				cout<<j<<' '<<i;
				return 0;
			}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
