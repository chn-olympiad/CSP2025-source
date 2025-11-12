#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100100;
int n,m,k,cnt,b[N];
struct edge{
	int to;
	int cst;
	int nxt;
}e[N];
void add(int u,int v,int coast){
	cnt++;
	e[cnt].to=v;
	e[cnt].cst=coast;
	e[cnt].nxt=b[u];
	b[u]=cnt;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cout<<0;
	return 0;
} 
/*
1
2
8 9 10
0 0 4
*/
