#include<bits/stdc++.h>
using namespace std;
int t,n,maxx;
int a[20001][3],b[3]={0,0,0},st,ma,re;
bool flag=0;
/*int cmp(int m)
{
	int l=max(a[m][1],max(a[m][2],a[m][0]));
	for(int i=0;i<3;i++)
		if(a[m][i]==l)
			return i;
	//cout<<l;
	return 1;
}*/

void club(int sum,int num)
{
	if(sum>maxx)
	{
		maxx=sum;
		//cout<<maxx<<endl;
	}
	
	if(num>=n||maxx>=st) return;
	
	for(int i=0;i<3;i++)
	{
		if(b[i]<n/2)
		{
			b[i]++;
			club(sum+a[num][i],num+1);
			b[i]--;
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++)
	{
		st=0;
		maxx=-4;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
				ma=max(ma,a[i][j]);
				re=j;
			}
			st+=ma;
			b[re]++;
		}
   	
		for(int j=0;j<3;j++)
			if(b[j]>n/2) flag=1;
		if(flag)
		{
		 	for(int i=0;i<3;i++) b[i]=0;
		 	club(0,0);
		 	cout<<maxx<<"\n";
		}							
		else cout<<st;
	}
	return 0;
}
