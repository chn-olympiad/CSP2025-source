#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",a+i);
	int t=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int pos=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t) 
		{
			pos=i;
			break;
		}
	}
	int x=(pos+n-1)/n,y;
	pos%=n;
	if(x%2==1)
	{
		if(pos==0) y=n;
		else y=pos;
	}
	else
	{
		if(pos==0) y=1;
		else y=n+1-pos;
	}
	cout<<x<<' '<<y;
	return 0;
}
