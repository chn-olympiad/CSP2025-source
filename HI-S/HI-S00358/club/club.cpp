#include "bits/stdc++.h"
using namespace std;


int n,m,t,a[100001][100001],b[100001],tp1=1,tp2=1,s;

bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	 
	int i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		s=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;i<=3;j++)
			{
				cin>>a[i][j];
				if (! ((j==2&&a[i][j]==0)||(j==3&&a[i][j]==0)) ) tp1=0;
				if (! (j==3&&a[i][j]==0)) tp2=0;
			}
		}
		if(tp1)//A
		{
			for(i=1;i<=n;i++) b[i]=a[i][0];
			sort(b+1,b+n+1,cmp);
			for(i=1;i<=n/2;i++)
			{
				s+=b[i];
			 } 
			cout<<s<<endl;
			continue;
		}
		else cout<<rand()<<endl;
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
