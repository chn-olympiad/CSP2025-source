#include <bits/stdc++.h>
using namespace std;
long long read(){
	long long a=0;
	char c=getchar();
	while(c<'0' or c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	} 
	return a;
}
long long n,m,k;
long long fa[11111],ans,p[1111111],cnt,cost[11],tp;
long long b[122];//从2^0开始 从零开始 
struct str{
	long long u,v,w,mark;
}e[1111111];

void init(){
	int tp=0,sum=1;
	while(sum<=1024){
		b[tp]=sum;
		sum*=2;
		tp++;
	}
}

bool cmp(str a,str b){
	return a.w<b.w; 
}

long long up(long long gs){
	if(gs==fa[gs])return gs;
	fa[gs]=up(fa[gs]);
	return fa[gs];
}

long long qu(int key){
	cnt=0;
	long long ans=0;
	for(int i=1;i<=m+k*n;i++){
		if(b[e[i].mark] & key){//优化 
			p[++cnt]=i;
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
//	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
//		cout<<" "<<e[p[i]].u<<" "<<e[p[i]].v<<" "<<e[p[i]].w<<";";
		if(up(e[p[i]].u)!=up(e[p[i]].v)){
			ans+=e[p[i]].w;
			fa[up(e[p[i]].u)]=up(e[p[i]].v);
		}
	}
//	cout<<endl;
	return ans;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init(); 
	n=read();
	m=read();
	k=read();
	for(long long i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(long long i=0;i<k;i++){
		cin>>cost[i];
		for(long long j=1;j<=n;j++){
			cin>>tp;
			e[m+i*n+j].u=n+1+i;
			e[m+i*n+j].v=j;
			e[m+i*n+j].w=tp;
			e[m+i*n+j].mark=i+1;
		}
	}
	sort(e+1,e+1+k*n+m,cmp);
	ans=qu(1);
	for(long long i=1;i<(1<<k);i++){
		tp=0;
		for(long long j=0;j<k;j++){
			if(b[j]&i)tp+=cost[j];//优化 
		} 
		ans=min(ans,qu((i<<1)+1)+tp);
//		cout<<tp<<" "<<qu((i<<1)+1) <<endl;
	}
	cout<<ans;
	return 0;
} 
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
