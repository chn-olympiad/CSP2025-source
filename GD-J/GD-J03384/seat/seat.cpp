#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int rk=1;
	for(int i=1;i<=n*m;i++)cin>>a[i],rk+=(a[i]>a[1]);
	int x=(rk-1)/n+1;
	int y=(rk-1)%n+1;
	if(x%2==0)y=n-y+1;
	cout<<x<<' '<<y;
	return 0;
} 
