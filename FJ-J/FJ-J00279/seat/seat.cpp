#include<bits/stdc++.h>
using namespace std;
int n,m,a[225],r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) cin >> a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int i,j;
	for(i=1;i<=n*m;i++)
		if(r==a[i]) break;
	int x=1,y=1;
	for(j=1;j<i;j++){
		if(j%n==0) y++;
		else if(y%2==1) x++;
		else x--;
	}
	cout << y << " " << x;
	return 0;
}

