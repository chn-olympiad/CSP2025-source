#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],x=1,y=1,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	k=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==k)break;
		if(x%2==1)
		{
			y++;
			if(y==n+1)y=n,x++;
		}
		else{
			y--;
			if(y==0)y=1,x++;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
