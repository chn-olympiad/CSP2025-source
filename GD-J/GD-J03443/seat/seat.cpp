#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,x,js;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	s=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(s==a[i])
		{
			x=i;
			break;
		}
	}
	for(int i=1,j=1;i<=m;)
	{
		js++;
		if(js==x)
		{
			cout<<i<<" "<<j;
			break;
		}
		if(i%2==1)
		j++;
		else
		j--;
		if(i%2==1 && j==n)
		{
			js++;
			if(js==x)
			{
				cout<<i<<" "<<j;
				break;
			}
			i++;
		}
		if(i%2==0 && j==1)
		{
			js++;
			if(js==x)
			{
				cout<<i<<" "<<j;
				break;
			}
			i++;
		}
	}
	
	return 0;
}
