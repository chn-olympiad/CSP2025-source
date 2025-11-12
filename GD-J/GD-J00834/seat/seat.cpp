#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int b;
	int c;
}a[11111]; 
bool cmd(aaa x,aaa y)
{
	return x.c>y.c;
}
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<(n*m);i++)
	{
		cin>>a[i].c;
		a[i].b=i;
	}
	sort(a,a+(n*m),cmd);
	for(int i=0;i<(n*m);i++)
	{
		if(a[i].b==0)
		{
			int l=i/n+1;
			if(l%2==1)
			{
				cout<<l<<" "<<i%n+1;
			} 
			else
			{
				cout<<l<<" "<<n-(i%n);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
