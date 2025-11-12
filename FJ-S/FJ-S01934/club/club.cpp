#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int f,s,t;
};
struct edge{
	int c;
	int n;
	int w;
};
bool cmp(edge a,edge b){
	return a.c>b.c;
}
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		int m=read();
		node a[N];
		int tot=1;
		edge x[N];
		bool vis[N];
		long long ans=0;
		for(int i=1;i<=m;i++){
			a[i].f=read();
			a[i].s=read();
			a[i].t=read();
			x[tot].c=a[i].f;
			x[tot].n=i;
			x[tot].w=1;
			tot++;
			x[tot].c=a[i].s;
			x[tot].n=i;
			x[tot].w=2;
			tot++;
			x[tot].c=a[i].t;
			x[tot].n=i;
			x[tot].w=3;
			tot++;
		}
		sort(x+1,x+tot,cmp);
		int sum[3]={};
		for(int i=1;i<=tot*3;i++){
			if(sum[x[i].w]+1<=m/2&&!vis[x[i].n]){
				ans=ans+x[i].c;
				vis[x[i].n]=1;
				sum[x[i].w]=sum[x[i].w]+1;
			}
		}
		cout<<ans;
	}
	return 0;
}
