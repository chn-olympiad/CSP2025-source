#include<bits/stdc++.h>
using namespace std;
int a[1005];
int k,len,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[len++];
			if(i==0&&j==0)
			k=a[len-1];
		}
	}
	sort(a,a+len);
	int d=lower_bound(a,a+len,k)-a;
	d=len-d;
	int x,y;
	x=(d+n-1)%n+1;
	y=(d+n-1)/n;
	if(y%2==0)
	{
		x=n-x+1;
	}
	cout<<y<<" "<<x;
	return 0;
}
