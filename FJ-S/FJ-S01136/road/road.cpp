#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100000;
int n,m,k,fa[10050],p[10050];
long long c[15][10050],final_res=9e18;
void merge(int x,int y){
	fa[x]=fa[y];
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct node{
	int u,v;
	long long w;
	friend bool operator < (node A,node B){
		return A.w<B.w;
	}
}a[N];
priority_queue<node> q;
void solve1(){	//+16pts
	sort(a+1,a+m+1);
	int k=0;long long res=0;
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			merge(a[i].u,a[i].v);
			res=res+a[i].w;
			k++;
		}
		if(k==n-1)break;
	}
	cout<<res;
}
long long Solve(int num){
	int M=m;long long ans=0;
	for(int i=1;i<=num;i++){
		ans=ans+c[p[i]][0];
		for(int j=1;j<=n;j++){
			a[++M]={n+i,j,c[p[i]][j]};
		}
	}
	sort(a+1,a+M+1);
	int k=0;
	for(int i=1;i<=M;i++){
		if(find(a[i].u)!=find(a[i].v)){
			merge(a[i].u,a[i].v);
			ans=ans+a[i].w;
			k++;
		}
		if(k==n+num-1)break;
	}
	return ans;
}
void solve2(int num,int now){	//+16pts
	long long res=9e18;
	if(num==k){
		for(int i=1;i<=10010;i++)fa[i]=i;
		res=min(res,Solve(num));
		return;
	}else{
		for(int i=1;i<=10010;i++)fa[i]=i;
		res=min(res,Solve(num));
	}
	for(int i=now;i<=k;i++){
		p[num+1]=i;
		solve2(num+1,i+1);
	}
	final_res=min(final_res,res);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=10010;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)scanf("%lld",&c[i][j]);
	if(k==0)solve1();
	else if(k<=5&&m<=100000){
		solve2(0,1);cout<<final_res;
	}else{	//+rand()%68 pts
		final_res=Solve(0);
		for(int i=1;i<=k;i++){
			long long x=0;
			for(int j=0;j<=n;j++)x=x+c[i][j];
			final_res=min(final_res,x);
		}
		cout<<final_res;
	}
	return 0;
}
