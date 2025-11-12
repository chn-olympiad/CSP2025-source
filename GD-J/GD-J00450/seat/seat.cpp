#include<algorithm>
#include<iostream>
using namespace std;
int a[101],c,i,m,n,r,tmp,xr;
bool cmp(int n1,int n2){
	return n1>n2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=m*n;i++)cin>>a[i];
	xr=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(i=1;i<=m*n;i++){
		if(a[i]==xr){
			tmp=i-1;
			break;
		}
	}
	c=tmp/m+1,r=tmp%n+1;
	if(r==0)r=n;
	if(c%2==0)r=n+1-r;
	cout<<c<<' '<<r;
	return 0;
}
