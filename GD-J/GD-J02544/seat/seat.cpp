#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],tmp,x=1,y=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	tmp=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==tmp){
			cout<<y<<' '<<x<<endl;
			break;
		}
		if(y%2==1)
		{
			if(x==n) y++;
			else x++;
		}
		else
		{
			if(x==1) y++;
			else x--;
		}
	}
	return 0;
}
