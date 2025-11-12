#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int n, m, k, min_cw=0x3f, min_aw[N], min_bw[N];
struct A{
	int u, v, w;
}a[N];

struct C{
	int w;
	int b[N];
}c[11];

bool cmp1(A x, A y){
	if(x.w!=y.w)return x.w<y.w;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(min_aw, 0x3f, sizeof(min_aw));
	memset(min_bw, 0x3f, sizeof(min_bw));
	cin>>n>>m>>k;
	for(int i=0; i<m; i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		min_aw[i]=min(min_aw[i], a[i].w);
	}
	for(int i=0; i<k; i++){
		cin>>c[i].w;
		min_cw=min(min_cw, c[i].w);
		for(int j=0; j<n; j++){
			cin>>c[i].b[j];
			min_bw[i]=min(min_bw[i], c[i].b[j]); 
		}
	}

	sort(a, a+n, cmp1);
	
	for(int i=0, j=0; i<m || j<n; i++, j++){
		if(min_aw[i]>min_bw[j]) min_aw[i]=min_bw[j];
	}
	
	int res=0;
	for(int i=0; i<m-1; i++){
		res+=min_aw[i];
	}
	for(int i=0; i<m; i++){
		cout<<min_aw[i]<<" ";
	}
	cout<<endl;
	cout<<res+min_cw<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
