#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

const int N=1e1;

int n,m;
int a[N*N+1];

int x,y;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int R=a[1];
	
	sort(a+1,a+1+n*m);
	
	int pos=lower_bound(a+1,a+1+n*m,R)-a;
	pos=n*m-pos+1;
	
	y=(pos-1)/n+1;
	pos-=n*(y-1);
	
	if(y&1) x=pos;
	else x=n-pos+1;
	
	cout<<y<<' '<<x;
	
	return 0;
}

