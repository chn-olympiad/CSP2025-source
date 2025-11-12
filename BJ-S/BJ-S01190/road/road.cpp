#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+100,M=1e6+500,K=15;
int n,m,k;
struct Ed{
	int a,b;
	ll l;
}edge[M];
struct to{
	int id;
	ll l;
}len[K][N];
int tt[K],id[N];
int cnt,tot;
ll ans,Ans=LONG_LONG_MAX,c[K],mx[K],t;
int fa[N],num;
bool cmp1(Ed a,Ed b){
	return a.l<b.l;
}
bool cmp2(to a,to b){
	return a.l<b.l;
}
void clear(){
	cnt=tot=0;
	for(int i=0;i<=k;i++)id[i]=1;
	memset(tt,0,sizeof(tt));
	ans=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
}
Ed get_ed(){
	Ed res=edge[id[0]];
	int fr=0;
	for(int i=1;i<=cnt;i++){
		if(id[i]<=mx[tt[i]] && len[tt[i]][id[i]].l<res.l){
			res={tt[i]+n,len[tt[i]][id[i]].id,len[tt[i]][id[i]].l};
			fr=i;
		}
		num++;
	}
	id[fr]++;
	return res;
}
int get(int a){
	if(fa[a]==a)return a;
	return fa[a]=get(fa[a]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//freopen();
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&edge[i].a,&edge[i].b,&edge[i].l);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&len[i][j].l);
			len[i][j].id=j;
		}
	}
	sort(edge+1,edge+1+m,cmp1);
	for(int i=0;i<(1<<k);i++){
		int tmp=i,ip=1;
		clear();
		while(tmp){
			if(tmp&1){
				tt[++cnt]=ip;
				ans+=c[ip];
			}
			tmp>>=1;
			ip++;
		}
		//cout<<ans<<endl;
		while(tot<n-1+cnt){
			Ed f=get_ed();
			f.a=get(f.a);
			f.b=get(f.b);
			if(f.a!=f.b){
				fa[f.a]=f.b;
				tot++;
				ans+=f.l;
				if(!i)t=max(t,f.l);
				if(ans>=Ans)break;
				//cout<<f.l<<' '<<f.a<<' '<<f.b<<endl;
			}
		}
		//cout<<i<<':'<<ans<<endl;
		Ans=min(Ans,ans);
		if(i==0){
			for(int i=1;i<=k;i++)sort(len[i]+1,len[i]+1+n,cmp2);
			for(int i=1;i<=k;i++)for(int j=1;j<=n;j++){
				if(len[i][j].l>t){
					mx[i]=j-1;
					break;
				}
				else if(j==n)mx[i]=n+1;
			}
		}
	}
	printf("%lld",Ans);//cout<<endl<<num<<endl;
	return 0;
}