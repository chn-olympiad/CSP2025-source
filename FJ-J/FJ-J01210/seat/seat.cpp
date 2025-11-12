#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],p,d,c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==p){
			d=i;
			break;
		}
	c=d/n+1;
	if(d%n==0){
		c=d/n;
		if(c%2) r=n;
		else r=1;
	}
	else if(c%2) r=d%n;
	else r=n-d%n+1;
	cout<<c<<' '<<r;
}
