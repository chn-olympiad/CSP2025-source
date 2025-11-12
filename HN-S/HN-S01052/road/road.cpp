#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int M=1e6+20;
const int K=15;
const int N=1e4+10;
const int INF=0x3f3f3f3f;
int n, m, k;
struct Node1{
	int u, v, w;
}a[M];
struct Node2{
	int c;
	int a[N];
}b[K];
int pre[N];
int Dijistra(int s){
	int sum=0;
	for(int i=0; i<m; i++){
		if(pre[a[i].v]==0 || a[i].w<pre[a[i].v]){
			pre[a[i].v]=a[i].w;
			if(pre[a[i].u]==INF){
				pre[a[i].u]=0;
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(pre[i]!=INF){
			sum+=pre[i];
		}
		else return INF;
	}
	return sum;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	//
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i<m; i++){
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	}
	b[0].c=INF;
	memset(pre, INF, sizeof(pre));
	int sum=Dijistra(0);
	for(int i=0; i<k; i++){
		scanf("%d", &b[i].c);
		for(int j=0; j<n; j++){
			scanf("%d", &b[i].a[j]);
			b[i].a[j]+=b[i].c;
		}
	}
	printf("%d", sum);
	//
	fclose(stdin);
	fclose(stdout);
	return 0;
}

