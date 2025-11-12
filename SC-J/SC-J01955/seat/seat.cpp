#include <bits/stdc++.h>
using namespace std;
/*!@#$%^&*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
const int N=15;
int n,m;
int rs;
int a[N*N];
/*!@#$%^&*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
bool cmp(int x,int y){
	return x>y;
}
/*!@#$%^&*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	rs=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(rs==a[i]){
			rs=i;
			break;
		}
	int x=rs,y=0;
	while(x>n) x-=n,y++;
	if(y&1) x=n-x+1;
	cout<<y+1<<' '<<x<<'\n';
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

4 5
10 1 2 3 4 5 6 7 8 9 11 12 13 14 15 16 17 18 19 20
*/