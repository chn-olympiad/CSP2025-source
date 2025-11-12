#include<bits/stdc++.h>
using namespace std;
int m,n,a[100];
int cnp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int test=a[1],s;//排名
	sort(a+1,a+1+m*n,cnp);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==test)
			s=i;
	}
	int hang=1;//控制上下行
	int i=1,j=1,k=1;
	while(k<s)
	{
		if(hang==1&&i!=n)
		{
			i++;
		}
		else if(i==n&&hang==1)
		{
			j++;
			hang*=-1;
		}
		else if(hang==-1&&i!=1)
		{
			i--;	
		}
		else if(i==1&&hang==-1)
		{
			j++;	
			hang*=-1;	
		}			
		k++;
	}
	cout<<j<<" "<<i;
	return 0;
}