#include<bits/stdc++.h>
using namespace std;

int n;//n<=10^4 表示城市个数 
int m;//m<=10^6 表示道路（边）数 
int k;//k<=10 表示乡村数 
struct edge{
	int u,v,val;
};
edge e[1000010];
int cnt=0;

int cost[15];

void add(int u,int v,int val){
	cnt++;
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt].val=val;
} 

//int ans=0;
//int ans1=0; 
//void count(int i,int End){
//	ans1+=e[i].val;
//	if(e[i].u>n) ans+=cost[e[i].u];
//	else if(e[i].v>n) ans+=cost[e[i].v];
//	if(e[i].v==End) return;
//	for(int j=1;j<=m;j++) if(e[j].u==e[i].v) count(j,End);
//}

void A(){//n<=10^4,m<=10^6,k<=10
	
	printf("%d\n",ans);
}

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    int a,b,c;
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d",&a,&b,&c);
    	add(a,b,c);
    	add(b,a,c);
	}
	bool qwe=1,asd=0; 
	for(int i=1;i<=k;i++){
		scanf("%d",&cost[i]);
		if(cost[i]!=0) qwe=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&c);
			if(c==0) asd=1;
			add(n+i,j,c);
			add(j,n+i,c);
		} 
	}
	if(qwe&&asd){
		A();
		return 0;
	}
//	for(int i=1;i<=m;i++){
//		int End=e[i].u;
//		count(i,End);
//		ans=min(ans,ans1);
//	}
	printf("%d\n",ans);
	return 0;
}

