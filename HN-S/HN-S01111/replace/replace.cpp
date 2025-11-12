#include<bits/stdc++.h>
using namespace std;

string s[200005][3] , t[200005][3];
int pos[200005][3] , Pos[200005][3] , answ[500005];
int n , q;
const int M = 5e6;
struct node{
	int x , y;
};
vector<node> g[2 * M + 5];
bool cmp(node l , node r){
	int tmp = ( l.y ? Pos[l.x][1] : pos[l.x][1] );
	int Tmp = ( r.y ? Pos[r.x][1] : pos[r.x][1] );
	if( tmp == Tmp ) return l.y < r.y;
	return tmp < Tmp;
}
int tree[2 * M + 5];
int lowbit(int x){
	return x & -x;
}
void add(int x , int y){
	while(x <= 2 * M){
		tree[x] += y;
		x += lowbit(x);
	}
}
int qry(int x){
	int res = 0;
	while(x){
		res += tree[x];
		x -= lowbit(x);
	}
	return res;
}
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> q;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> s[i][1] >> s[i][2];
		for( int j = 0 ; j < s[i][1].size() ; j++ ){
			if( s[i][1][j] == 'b' ) pos[i][1] = j;
		}
		for( int j = 0 ; j < s[i][2].size() ; j++ ){
			if( s[i][2][j] == 'b' ) pos[i][2] = j;
		}
		g[pos[i][1] - pos[i][2] + M].push_back({i , 0});
	} 
	for( int i = 1 ; i <= q ; i++ ){
		cin >> t[i][1] >> t[i][2];
		if( t[i][1].size() != t[i][2].size() )	continue;
		int ans = 0;
		for( int j = 0 ; j < t[i][1].size() ; j++ ){
			if( t[i][1][j] == 'b' ) Pos[i][1] = j;
		}
		for( int j = 0 ; j < t[i][2].size() ; j++ ){
			if( t[i][2][j] == 'b' ) Pos[i][2] = j;
		}
		g[Pos[i][1] - Pos[i][2] + M].push_back({i , 1});
	}
	for( int i = 1 ; i <= M * 2 ; i++ ){
		sort(g[i].begin() , g[i].end() , cmp);
	}
	for( int i = 1 ; i <= M * 2 ; i++ ){
		for( int k = 0 ; k < g[i].size() ; k++ ){
			node j = g[i][k];
			if(j.y)	answ[j.x] = qry(t[j.x][1].size() - Pos[j.x][1]);
			else	add(s[j.x][1].size() - pos[j.x][1] , 1);
		}
		for( int k = 0 ; k < g[i].size() ; k++ ){
			node j = g[i][k];
			if(!j.y) add(s[j.x][1].size() - pos[j.x][1] , -1);
		}
	}
	for( int i = 1 ; i <= q ; i++ ) cout << answ[i] << "\n";
	return 0;
} 
