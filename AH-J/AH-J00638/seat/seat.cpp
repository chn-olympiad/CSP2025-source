#include<bits/stdc++.h>
using namespace std;
int a[125];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	int c=1,r=1,t=1;
	while(1)
	{
		if(a[t]==x)
		{
			cout<<c<<' '<<r<<endl;
			return 0;
		}
		if(c%2==1&&r!=n) r++;
		else if(c%2==1) c++;
		else if(r!=1) r--;
		else c++;
		t++;
	}
	return 0;
}
