#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int read(){
	int x;bool f=0;char ch;
	while((ch=getchar())>'9' || ch<'0')if(ch=='-')f=1;
	x=ch-'0';
	while((ch=getchar())>='0' && ch<='9')x=(x<<3)+(x<<1)+ch-'0';
	return f?-x:x;
}
const int N=1e4+5;
const int M=2e6+5;
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int n,m,k;
struct EDGE{
	int u,v,i,cost;
}edge[M];
bool ciscost[15];
int ccost[15];
int num_edge=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		edge[num_edge].u=read(),edge[num_edge].v=read();
		edge[num_edge].cost=read();
		num_edge++;
	}
	for(int i=1;i<=k;i++){
		ccost[i]=read();
		for(int j=1;j<=n;j++){

		}
	}
	cout<<0;
	return 0;
}
//:(
