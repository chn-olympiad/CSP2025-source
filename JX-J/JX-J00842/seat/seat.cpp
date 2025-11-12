#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],num=1,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int all=n*m;
	cin>>a[1];
	for(int i=2;i<=all;i++){
		cin>>a[i];
		if(a[i]>a[1])num++;
	}
	x=(num-1)/n+1;
	y=all%n;
	if(y==0)y=n;
	if(y%2==1)y=n+1-y;
	cout<<x<<' '<<y;
	return 0;
}
