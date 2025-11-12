#include<bits/stdc++.h>
using namespace std;
const int N = 11,M = 11;
int n,m;
int a[N*M];
int d,f;
bool cmp(int x,int y){
	return x>y;
}
void solve(int x,int y,int s,int c){
	if(c==f){
		cout << y << ' ' << x;
		return;
	}
	if(s==1){//向下走 
		solve(x+1,y,(x+1==n?2:1),c+1);
	}
	else if(s==2){//向右走 
		solve(x,y+1,(y%2==0?1:3),c+1);
	}
	else{//向上走
		solve(x-1,y,(x-1==1?2:3),c+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)cin >> a[i];
	d = a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i = 1;i <= n*m;i++){
		if(d==a[i])f = i;
	}
	if(n==1)cout << 1 << ' ' << f;
	else if(m==1)cout << f << ' ' << 1;
	else solve(1,1,(n==1?2:1),1);
	return 0;
}

