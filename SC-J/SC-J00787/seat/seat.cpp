#include<bits/stdc++.h>
using namespace std;
int x,ans,row;
bool cmp(int a,int b)
{
	return a>b;
	
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	
	int num[n*m+1];
	for(int i=1;i<=n*m;i++)
	{
		cin>>x;
		num[i]=x;
	}
	int a1=num[1];
	sort(num+1,num+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++)
	{
		if(num[i]==a1)
		{
			ans=i;
			break;
		}
	}
	int line=ans/n;
	if(ans%n!=0)
	{
		line++;
	}
	
	
	if(line%2==0)
	{
		row=n-(ans%n)+1;
	}
	else
	{
		row=ans%n;
		
	}
	if(row==0)
	{
		row++;
	}
	if(row>n)
	{
		row--;
	}
	cout<<line<<" "<<row;
	
	return 0;
		
	
		
	
}