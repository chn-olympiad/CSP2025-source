#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7,maxm=2e6+7,maxk=20;

int n,m,k,cnt,u,v,w,ans;
struct stu{
	int ui,vi,wi;
}e[maxn];
int fa[maxn];

int in(){
	int t=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		t=(t<<3)+(t<<1)+(c^48);
		c=getchar();
	}
	return t*f;
}

void out(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x^48);
	else out(x/10),putchar(x%10^48);
}

int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}

void add(int x,int y,int z){
	e[++cnt]={x,y,z};
}

bool cmp(stu a,stu b){
	return a.wi<b.wi;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in(),m=in(),k=in();
	for(int i=1;i<=m;i++){
		u=in(),v=in(),w=in();
		add(u,v,w);
		add(v,u,w);
	}
	sort(e+1,e+1+cnt,cmp);
	cnt=0;
	int cur=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	while(cnt<n-1){
		cur++;
		if(getfa(e[cur].ui)==getfa(e[cur].vi)){
			continue;
		}
		else{
			cnt++;
			ans+=e[cur].wi;
			fa[getfa(e[cur].ui)]=getfa(e[cur].vi);
		}
	}
	out(ans);
	return 0;
}