#include<bits/stdc++.h>
using namespace std;
int n,m;
int z[110];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a=1,b=1,c=0,d=0,sum;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>z[i];
	}
	sum=z[1];
	sort(z+1,z+n*m+1,cmp);
	if(n==1)
	{
		for(int i=1;i<=n*m;i++)
		{
			if(z[i]==sum)
			{
				cout<<n<<" "<<i;
				return 0;
			}
		}
	}
	if(m==1)
	{
		for(int i=1;i<=n*m;i++)
		{
			if(z[i]==sum)
			{
				cout<<i<<" "<<m;
				return 0;
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(z[i]!=sum)
		{
			a++;
			d++;
			if(d==m) 
			{
				d=1;
				b++;
			} 
		}
		else
		{
			break;
		}
	}
	a%=n;
	if(a==0)
	{
		a=n;
	}
	else if(a==1)
	{
		if(b%2==0)
		a=n;
		else
		a=1;
	}
	cout<<b<<" "<<a<<'\n';
	return 0;
}
