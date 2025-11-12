#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],cnt=0,l,h;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i>=2&&a[i]>a[1]) cnt++;
	}
	cnt++;
	l=cnt/n;h=cnt%n;
	if(h) l++;
	else if(!h) h=n;
	if(l%2==0) h=n-h+1;
	printf("%d %d",l,h);
	return 0;
}
