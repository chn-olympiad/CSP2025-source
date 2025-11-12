//杜庹钊
//GZ-S00251
//安顺市第一高级中学

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

#define int long long

int n,m,k;

using namespace std;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int MIN[k+10]={0};	
	int city[m+5][m+5];
	int country[k+5][n+5];
	for(int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		cin>>city[x][y];
		MIN[0]+=city[x][y];
	}
	
	
	
	for(int i=1;i<=k;++i)
	{
		for(int j=0;j<=n;++j)
		{
			cin>>country[i][j];
			MIN[i]+=country[i][j];
		}
	}
	
	int city1[m+5][m+5]={0};
	int country1[k+5]={0};//是否修乡村 
	
	int ans=99999999999999;
	
	for(int i=0;i<=k;++i)
	{
		ans=min(ans,MIN[i]);
	}
	
	cout<<ans<<"\n";
	
	return 0;
 } 
 
 
/*  orz		   orz
	####       ####
	&&&&       &&&&
	&&&&	   &&&&
~~~~****+++++++****~~~~
||||@@@@"""""""@@@@||||
\\\\????///////????\\\\
*/
