#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
void fu(int t)
{
	int x=t/n+(t%n!=0);
	int y=t%n;
	if(y==0) y=n;
	if(x%2==0) y=n-y+1;
	cout<<x<<' '<<y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++) cin>>a[i];
	int st=a[1];
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=s;i++)
	{
		if(a[i]==st)
		{
			fu(i);
			return 0;
		}
	}
	return 0;
}
