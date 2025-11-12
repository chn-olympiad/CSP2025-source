#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt=0,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
		}
	y=(cnt+1)/m;
	if((cnt+1)%m!=0) y=y+1;
	if(y%2==1) x=y%m+1;
	if(y%2==0) x=m-y%m;
	cout<<y<<" "<<x;
	return 0;
	}
