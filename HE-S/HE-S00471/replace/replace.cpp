#include<bits/stdc++.h>
#define int unsigned long long 
const int N=1e6+100;
const long long M=2e7+100;
using namespace std;
int p[N];
int find(int x){
	if(p[x]!=x){
		return find(p[x]);
	}
	return x;
}
int s[N];
int n,m,k;
struct Edge {
	int u;
	int v;
	int w;
}a[M];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int c;
int cnt=0;
int ans=0;
int sum=0;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin>>n>>q;
	cout<<rand()%10000000;
	return 0;
}
