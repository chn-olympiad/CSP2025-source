#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,tar,cnt=1;
	cin>>n>>m;
	int a[n*m+1]={0};
	for(int i=1;i<=n*m;i++) cin>>a[i];
	tar=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int x=1,y=1;
	while(tar!=a[cnt])
	{
		if((y==n&&x%2)||(y==1&&!(x%2))) x++;
		else if(x%2) y++;
		else y--;
		cnt++;
	}
	cout<<x<<' '<<y;
	return 0; 
}
