#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,h,l;
int r,a,t=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a);
		if(a>r) t++;
	}
	l=(t-1)/n+1;
	h=(t-1)%n+1;
	if(l%2==0) h=m+1-h;
	cout<<l<<" "<<h;
	return 0;
}

