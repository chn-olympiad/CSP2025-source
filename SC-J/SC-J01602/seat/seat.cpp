#include<bits/stdc++.h>
using namespace std; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int ansa,anscnt;
	cin>>n>>m;
	cin>>ansa;
	anscnt=1;
	for(int i=2;i<=n*m;i++)
	{
		int a;
		cin>>a;
		if(a>ansa)
		{
			anscnt++;
		}
	}
	int t1=anscnt/n;
	int t2=anscnt%n;
	if(t1%2==1)
	{
		if(t2==0)
		{
			cout<<t1<<" "<<n;
		}
		else
		{
			cout<<t1+1<<" "<<n-t2+1;
		}
	}
	else
	{
		if(t2==0)
		{
			cout<<t1<<" "<<1;
		}
		else
		{
			cout<<t1+1<<" "<<t2;
		}
	} 
	return 0;
}