#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n,m;
int allm;
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>n;
vector<int>mathal(n,0);
for(int i=1;i<=n;i++)
{
	cin>>m;
	vector<int> xqt(3.0);
	vector< vector<int> > xq(m+1,xqt);
	vector<int> geren(4,0);
	for(int j=1;j<=m;j++)
	{
		for(int k=1;k<=3;k++)
		{
			cin>> geren[2];
		}
		int zuida=0;
		zuida=max(geren[1],max(geren[2],geren[3]));
		if(zuida==geren[1])
			push_back(xq[1][m],geren[1]);
			else if(zuida==geren[2])
				push_back(xq[2],geren[2]);
				else
				push_back(xq[3],geren[3]);
		sort(xq[1].begin(),xq[1]end());
		sort(xq[2].begin(),xq[2].end());
		sort(xq[3].begin(),xq[3].end());
		allm=xq[1][n/2]+xq[2][n/2]+xq[3][n/2];
		mathall[n]=allm;
	}
	mathall[n]=allm;
}
for(int i=0;i<=n;i++)
{
cout<<mathall[i];
}
fclose(stdin);
fclose(stdout);
}
