#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st{
	int num,b;
}a[105];
bool cmp(st x,st y)
{
	return x.num>y.num;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{	
		cin>>a[i].num;
		a[i].b=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i].b==1)
		{
			sum=i;
			break;
		}
	int x=sum/n,y=sum%n;
	if(y==0)	y=n;
	else x++;
	if(x%2==1)	cout<<x<<" "<<y;
	else	cout<<x<<" "<<n-y+1;
	return 0;
} 