//GZ-S00006  遵义市播州区新蓝学校 仇佳艺 
#include <bits/stdc++.h>
using namespace std;
int cnt,cnt1,cnt2,cnt3;
int n,n1,n2,n3,maxe=INT_MIN;
int g[1000001][3];
bool v[1000001][3];
int findmax(int b)
{
	int a=0,c;
	for(int i=0; i<3; i++)
	{
		if(v[b][i]==0 && g[b][i]>=a)
		{
			a=g[b][i];
			c=i;
			v[b][i]=1;
		}
	}
	return c;
}
void dfs(int num)
{
	int k;
	for(int i=0; i<n; i++)
	{
	    k=findmax(i);
		if(n1<=n/2 && k==0)
		{
			cnt1=cnt1+g[i][0];
			n1++;
		}
		if(n2<=n/2 && k==1)
		{
			cnt2=cnt2+g[i][1];
			n2++;		
		}
		if(n3<=n/2 && k==2)
		{
			cnt3=cnt3+g[i][2];
			n3++;		
		}		
	}
	cnt=cnt1+cnt2+cnt3;
	if(cnt>num)
	{
		num=cnt;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>n;
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<3; k++)
			{
				cin>>g[j][k];
			}
		}
		dfs(maxe);
		cout<<cnt;
		cout<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
}

