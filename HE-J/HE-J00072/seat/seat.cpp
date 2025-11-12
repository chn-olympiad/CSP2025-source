#include<bits/stdc++.h>
using namespace std;

const int N = 102;
int n,m,cj,pm;
int a[N];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	cj=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==cj) 
		{
			pm=i;
			break;	
		} 
	}
	if(pm<=n)
	{
		cout<<1<<" "<<pm;
		return 0;
	}
	int ch=pm/n;
	int yu=pm%n;
	if(yu==0)
	{
		if(ch%2==0)
		{
			cout<<ch<<" "<<1;
		}
		else 
		{
			cout<<ch<<" "<<n;
		}
	}
	else 
	{
		if((ch+1)%2==0)
		{
			cout<<ch+1<<" "<<n-yu+1;
		}
		else 
		{
			cout<<ch+1<<" "<<yu;
		}
	}
	return 0;
}
