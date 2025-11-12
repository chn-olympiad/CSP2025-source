#include<bits/stdc++.h>
#define int long long
#define f(i , l , r) for(int i = l;i <= r;i ++)
#define d(i , l , r) for(int i = r;i >= l;i --)
#define lowbit(x) ((x)&-(x))
#define pii pair<int,int>
#define fi first 
#define sc second
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int N = 2e5 + 10;
int n , st[3][N] , h;
struct node{
	int x , y , z;
}a[N];
bool cmp1(node a,node b){return a.x > b.x;}
bool cmp2(node a,node b){return a.y > b.y;}
bool cmp3(node a,node b){return a.z > b.z;}
void work(){
	cin >> n;
	f(i , 1 , n)cin >> a[i].x >> a[i].y >> a[i].z;
	int res = 0 , cnt0 = 0 , cnt1 = 0  ,cnt2 = 0;
	f(i , 1 , n){
		int c = max(a[i].x , max(a[i].y , a[i].z));
		res += c;
		if(a[i].x == c)st[0][++ cnt0] = c - max(a[i].y , a[i].z);
		else if(a[i].y == c)st[1][++ cnt1] = c - max(a[i].x , a[i].z);
		else st[2][++cnt2] = c - max(a[i].x , a[i].y);
	}
	if(cnt0 > n / 2){
		sort(st[0] + 1 , st[0] + 1 + cnt0);
		f(i , 1 , cnt0 - n/2)res -= st[0][i];
	}
	if(cnt1 > n / 2){
		sort(st[1] + 1 , st[1] + 1 + cnt1);
		f(i , 1 , cnt1 - n/2)res -= st[1][i];
	}
	if(cnt2 > n / 2){
		sort(st[2] + 1 , st[2] + 1 + cnt2);
		f(i , 1 , cnt2 - n/2)res -= st[2][i];
	}
	cout << res << "\n";
}
signed main(){
	fre("club");
	ios_base::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	int T;cin >> T;
	while(T --)work(); 
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
