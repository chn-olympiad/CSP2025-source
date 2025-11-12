#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int aa[N][N];
int nas=0;
int max_n;
int dfs1(int n)
{
	max_n=n/2;
	int ans=0;
	for(int i=1;i<=n;i++)
	{	
		int temp=0;
		int id,a=0,b=0,c=0;
		for(int j=1;j<=3;j++)
		{
			temp=max(temp,aa[i][j]);
			if(aa[i][j]==temp) id=j;
		}
		if(id==1&&a<max_n)
		{
			ans+=temp;
		}
		else if(id==2&&b<max_n) 
		{
			b++;
			ans+=temp;	
		}
		else  if(id==3&&c<max_n) 
		{
			c++;
			ans+=temp;
		}
		 
	}
	return ans;
}


int dfs2(int n){
	int temp=0;
	int ans=0;
	int id,a=0,b=0,c=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			temp=max(temp,aa[i][j]);
			if(aa[i][j]==temp) id=j;
		}
		if(id==1&&a<max_n)
		{
			ans+=temp;
		}
		else if(id==2&&b<max_n) 
		{
			b++;
			ans+=temp;	
		}
		else  if(id==3&&c<max_n) 
		{
			c++;
			ans+=temp;
		}
		
	}
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	for(int i=1;i<=t;i++)
	{	bool A=false;
		int n;
		cin >> n;
		max_n=n/2; 
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin >> aa[j][k];	
			}
			if(aa[j][3]==0&&aa[j][1]==0) A=true;
			
		}
		if(A)
		cout << dfs2(n)<<endl;
		else cout <<dfs1(n)<<endl; 
	
	}
	fclose(stdin);
	fclose(stdout);
	
 } 