#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	int rs;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r) rs=i;
	}
	int ans1=0,ans2;
	if(rs%n>0) ans1=1;
	ans1+=rs/n;
	if(ans1%2==1) ans2=(rs%n==0?n:rs%n);
	else ans2=n-(rs%n==0?n:rs%n)+1;
	cout<<ans1<<" "<<ans2;
	return 0;
}
