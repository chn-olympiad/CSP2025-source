#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+30;
const int M=1e4+30;
int tot,ppp,ttt,kkk;
int kb=0;
int f[N];
int c[20],ct[20][M];
struct node {
	int u,to,wi;
} e[N*2],us[N*2],tp[N+M*20],ling[N*2];
int find(int x) {
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
void add(int u,int v,int w) {
	tot++;
	e[tot]= {u,v,w};
}
void add4(int u,int v,int w) {
	kkk++;
	ling[kkk]= {u,v,w};
}
void add2(int u,int v,int w) {
	ppp++;
	tp[ppp]= {u,v,w};
}
void add3(int u,int v,int w) {
	ttt++;
	us[ttt]= {u,v,w};
}
bool cmp(node t1,node t2) {
	return t1.wi<t2.wi;
}
int n,m,k;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)f[i]=i;
	for(int i=1; i<=m; i++) {
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}

	sort(e+1,e+tot+1,cmp);
	long long sum=0;
	int cnt;
	for(int i=1; i<=tot; i++) {
		int uu=e[i].u;
		int vv=e[i].to;
		if(find(uu)!=find(vv)) {
			f[find(uu)]=find(vv);
			cnt++;
			sum+=e[i].wi;
			add3(uu,vv,e[i].wi);
			if(cnt==n-1)break;
		}
	}
	//for(int i=1; i<=ttt; i++)cout<<us[i].u<<" "<<us[i].to<<" "<<us[i].wi<<endl;
	sort(us+1,us+cnt+1,cmp);
	for(int i=1; i<=k; i++) {
		long long res=0,shu=0;
		//for(int i=1; i<=ttt; i++)cout<<us[i].u<<" "<<us[i].to<<" "<<us[i].wi<<endl;
		kkk=0;
		for(int o=1;o<=ttt;o++){
			add4(us[o].u,us[o].to,us[o].wi);
		}
		for(int p=1; p<=n+i; p++)f[p]=p;
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			int a;
			cin>>a;
			add3(n+i,j,a);
		}
		sort(us+1,us+ttt+1,cmp);
		//cout<<endl;
		for(int o=1; o<=ttt; o++) {
			int u=find(us[o].u);
			int v=find(us[o].to);
			if(u!=v) {
				f[u]=v;
				res+=us[o].wi;
				shu++;
				add2(us[o].u,us[o].to,us[o].wi);
				if(shu==n+kb)break;
			}
		}
		
		//cout<<shu<<" ";
		if(sum-res>c[i]) {
			//cout<<i<<"&";
			ttt=0;
			for(int q=1; q<=shu; q++) {
				add3(tp[q].u,tp[q].to,tp[q].wi);
			}
			ppp=0;
			kb++;
			sum=res+c[i];
		} else {
			ttt=0;
			for(int q=1;q<=kkk;q++){
				add3(ling[q].u,ling[q].to,ling[q].wi);
			}
			ppp=0;
			
		}
	}
	//for(int i=1;i<=ttt;i++)cout<<us[i].u<<" "<<us[i].to<<" "<<us[i].wi<<endl;
	cout<<sum<<'\n';
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
100 1 3 2 4
1 1 8 2 4



*/

