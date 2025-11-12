#include <bits/stdc++.h>
using namespace std;
int n,m,ans=1,x=1,y=1;
long long a[10015],sum;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	sum=a[1];
	sort(a+1,a+1+n*m,cmp);
	while(y<=m){
		while(x+1<=n){
			if(a[ans]==sum) goto A;
			ans++;
			x++;
		}
		if(a[ans]==sum) goto A;
		ans++;
		y++;
		while(x-1>=1){
			if(a[ans]==sum) goto A;
			ans++;
			x--;
		}
		if(a[ans]==sum) goto A;
		y++;
		ans++;
	}
	A:
	cout<<y<<' '<<x;
	return 0;
}
