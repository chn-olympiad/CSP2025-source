#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],a1,r=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	while(a[r]!=a1)r++;//п║R╣деецШ 
	if(r%n==0)
	{
		cout<<r/n<<" ";
		if(r/n%2==0)cout<<1;
		else cout<<n;
	}
	else
	{
		cout<<r/n+1<<" ";
		if((r/n+1)%2==0)cout<<n-r%n+1;
		else cout<<r%n;
	}
	return 0;
}
