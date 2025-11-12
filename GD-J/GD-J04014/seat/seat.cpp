#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int MR = 1e1 + 5;
const int MAXN = 1e2 + 5;
struct node{
	int s,id;
	bool operator < (const node & nd)const{return s > nd.s;}
}a[MAXN];
int p[MR][MR];
int n,m;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i].s,a[i].id = i;
	sort(a + 1,a + n * m + 1);
	int tag = 1;
	int cnt = 0;
	for(int j = 1;j <= m;j++){
		// for(int i = 1;i <= n;i += tag)
			// p[i][j] = a[++cnt].id;
		if(tag == 1){
			for(int i = 1;i <= n;i++)
				p[i][j] = a[++cnt].id;
		}
		else{
			for(int i = n;i >= 1;i--)
				p[i][j] = a[++cnt].id;
		}
		tag = -tag;
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(p[i][j] == 1){
				cout << j << ' ' << i << '\n';
				return 0;
			}
	return 0;
}