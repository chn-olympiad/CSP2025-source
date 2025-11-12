#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	//freopen("seat3.in","r",stdin);
	//freopen("seat3.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>s[i];
	int a=s[1];
	sort(s+1,s+(n*m)+1,cmp); 
	int c,r,pm;
	for(int i=1;i<=n*m;i++)
	{
		if(s[i]==a)
		{
			pm=i;
			break;
		}
	}
	if(pm%n==0)
	{
		c=pm/n;
		r=(c%2==0)?1:n;
	}
	else
	{
		c=pm/n+1;
		r=(c%2==0)?n-(pm%n-1):(pm%n);
	}
	cout<<c<<' '<<r;
	return 0;
}

