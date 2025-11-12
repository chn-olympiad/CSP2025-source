#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int st=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c=1,r=0;
	for(int i=1;i<=n*m;i++)
	{
		if(c%2==0)r--;
		else r++;
		if(r>n)
		{
			c+=1;
			r=n;
		}
		else if(r<1)
		{
			c+=1;
			r=1;
		}
		if(st==a[i]){
			cout<<c<<" "<<r;
			return 0;
		}
	}
	return 0;
}

