#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,R,pos=-1,line,row;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>a[i];
		if(i==1)
			R=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i)
		if(a[i]==R)
		{
			pos=i;
			break;
		}
	line=ceil(1.0*pos/n);
	if(line%2==1)
	{
		if(pos%n==0)
			row=n;
		else
			row=pos%n;
	}
	else
	{
		row=n-((pos-1)%n);
	}
	cout<<line<<" "<<row;
	return 0;
}
