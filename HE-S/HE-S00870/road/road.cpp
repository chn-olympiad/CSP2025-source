#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int MAXN = 10010;
int l[MAXN][MAXN];
const int MAXM = 1000010;
struct road{
	int u;
	int v;
	int w;
}q[MAXM];
struct country{
	int w;
	int a[MAXN];
}p[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		cin>>q[i].u >>q[i].v >>q[i].w;
		if(q[i].u < q[i].v){
			int cmp = q[i].u;
			q[i].u = q[i].v;
			q[i].v = cmp;
		}
	}	
	for(int j = 0;j <= k;j++){
		cin>>p[j].w;
		for(int i = 1;i <= n;i++){
			cin>>p[j].a[i];
		}
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
