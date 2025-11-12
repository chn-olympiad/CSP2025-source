#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
struct node{
	int c,s;
}A[101];
int cmp(node x,node y){
	return x.s > y.s;
}
void p(int cnt,int x,int y){
	if (A[cnt].c == 1){
		cout << y << " " << x << "\n";
		exit(0);
	}
}
void dfs(int x,int y,int cnt,bool f){
	if (x > n){
		x = n;
		y++;
		p(cnt,x,y);
		dfs(x - 1,y,cnt + 1,1);
	}
	if (x < 1){
		x = 1;
		y++;
		p(cnt,x,y);
		dfs(x + 1,y,cnt + 1,0);
	}
	p(cnt,x,y);
	if (f == 1){
		dfs(x - 1,y,cnt + 1,1);
	}else{
		dfs(x + 1,y,cnt + 1,0);
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++){
		cin >> A[i].s;
		A[i].c = i;
	}
	sort(A + 1,A + n * m + 1,cmp);
	dfs(1,1,1,0);//下0上1 
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/