#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+20,M=1e6+10;
int n,m,k;
struct side{
	int u,v,w;
	bool operator<(side b){
		return w<b.w;
	}
} s[M],t[2*M];
int ans=1e18;
int fa[N],len;
int tot;
int c[20],a[12][N];

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

void rd(int &x){
	x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

int kruskal(){
	int sum=0,cnt=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=len;i++){
		int u=t[i].u,v=t[i].v,w=t[i].w;
		int x=find(u),y=find(v);
		if(x==y)continue;
		fa[x]=y;
		cnt++;
		sum+=w;
		if(cnt==tot-1)break;
	}
	if(cnt<tot-1)return 1e18;
	return sum;
}

void subtask1(){
	for(int i=1;i<=len;i++)t[i]=s[i];
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			t[++len]={n+i,j,a[i][j]};
	sort(t+1,t+1+len);
	tot=n+k;
	ans=kruskal();
	printf("%lld",ans);
}

void subtask2(){
	for(int x=0;x<(1<<k);x++){
		len=m,tot=n;
		for(int i=1;i<=m;i++)t[i]=s[i];
		for(int i=1;i<=k;i++)
			if(x&(1<<(i-1))){
				tot++;
				for(int j=1;j<=n;j++)
					t[++len]={n+i,j,a[i][j]};
			}
		sort(t+1,t+1+len);
		ans=min(ans,kruskal());
	}
	printf("%lld",ans);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	rd(n),rd(m),rd(k);
	for(int i=1;i<=m;i++){
		rd(s[i].u);
		rd(s[i].v);
		rd(s[i].w);
	}
	len=m;
	for(int i=1;i<=k;i++){
		rd(c[i]);
		for(int j=1;j<=n;j++)rd(a[i][j]);
	}
	bool flag=1;
	for(int i=1;i<=k;i++)
		if(c[i]!=0)flag=0;
	if(flag)subtask1();
	else subtask2();
	return 0;
}
