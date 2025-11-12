#include<bits/stdc++.h>
using namespace std;
template<typename P>
inline void read(P &x){
	P res = 0, f = 1;
	char ch = getchar();
	while(ch <'0' || '9' <ch){
		if(ch=='-')f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		res = (res*10) + (ch -'0');
		ch = getchar();
	}
	x = res * f;
}
template <typename Ty, typename ...Args>
inline void read(Ty &x, Args &...args){read(x);read(args...);}
const int N = 15;
int ans[N][N];
int dx[] = {1, -1}, dy[] = {0, 0};
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, R;
	read(n, m);
	vector<int>a(n*m+1);
	for(int i=1; i<=n*m; ++i)read(a[i]);
	R=a[1];
	sort(a.begin()+1, a.end(), greater<int>());
	int x=1, y=1, pos=0;
	for(int i=1;i<=n*m; ++i){
		ans[x][y] = a[i];
		if((x==n&&pos==0)||(x==1&&pos==1)){
			y++;
			pos=1-pos;
		}
		else{
			x=x+dx[pos];
			y=y+dy[pos];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(ans[i][j] == R){
				cout << j << ' ' << i << '\n';
				return 0;
			}
		}
	}
	return 0;
}