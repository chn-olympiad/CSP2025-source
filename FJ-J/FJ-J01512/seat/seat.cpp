#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int n,m,rank;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)if(x==a[i])rank=n*m-i+1;
	cout<<ceil(rank*1.0/n)<<' ';
	if(rank%(n*2)==0)cout<<1;
	else if(rank%(n*2)<=n)cout<<rank%(n*2);
	else cout<<n-(rank%(n*2)-n)+1;
	return 0;
}
