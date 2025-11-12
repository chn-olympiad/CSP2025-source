#include<bits/stdc++.h>
using namespace std;
int a[110],s[110][5];
int main()
{
	int i,n,m,x,n1=0,m1=1;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(i=1;i<=n*m;i++)
	{
		if(m1%2==1&&n1+1>=1&&n1+1<=n)
		{
			s[a[i]][1]=m1;
			s[a[i]][2]=++n1;	
		}
		else if(m1%2==1&&n1+1>n)
		{
			s[a[i]][1]=++m1;
			s[a[i]][2]=n1;
		}
		else if(m1%2==0&&n1-1>=1&&n1-1<=n)
		{
			s[a[i]][1]=m1;
			s[a[i]][2]=--n1;
		}
		else if(m1%2==0&&n1-1<1)
		{
			s[a[i]][1]=++m1;
			s[a[i]][2]=n1;
		}
	}
	cout<<s[x][1]<<' '<<s[x][2]<<endl;
	return 0;
}
