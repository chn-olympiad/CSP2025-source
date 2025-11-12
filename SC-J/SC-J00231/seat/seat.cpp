# include"bits/stdc++.h"
using namespace std;
int main()
{	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,b=1,x=1,y=1,a[110];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=2;i<=n*m;i++)if(a[i]>a[1])b++;
	long long i=1;
	while(i<=n*m&&i<b)
		{while(y<n&&i<b)
			{y++;
			i++;}
		if(y==n&&i<b)
			{x++;
			i++;}
		while(y>1&&i<b)
			{y--;
			i++;}
		if(y==1&&i<b)
			{x++;
			i++;}}
	if(i==b)cout<<x<<' '<<y<<endl;
	return 0;
}