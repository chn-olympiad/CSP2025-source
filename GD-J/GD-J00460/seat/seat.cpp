#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000006
ll n,m,a[N],cnt,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){cin>>a[i];if(a[i]>=a[1]) cnt++;}
	y=cnt/n+(cnt%n!=0);
	if(y%2==1) x=cnt-(y-1)*n;
	else x=n-(cnt-(y-1)*n)+1;
	cout<<y<<" "<<x<<endl;
	return 0;
}
