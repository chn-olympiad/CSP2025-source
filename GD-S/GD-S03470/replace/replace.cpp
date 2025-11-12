#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5,M=5e6+5,mod=1e9+7,MOD=1e9+9,base=1331,BASE=131;
struct Node{
	string l,r;
	bool op;
	int hs1,hs2,id;
}a[N];
bool cmp(Node x,Node y){
	return x.hs1==y.hs1?x.hs2<y.hs2:x.hs1<y.hs1;
}
int n,q,f[M][26],g[M][26],ans[N],fid,gid;
int sg[M];
vector<string>sf[M];
vector<pair<int,string> >qu[M];
void add1(Node x){
	string s=x.l;
	int p=1;
	for(int i=0;i<s.size();i++){
		int to=s[i]-'a';
		if(!f[p][to])f[p][to]=++fid;
		p=f[p][to];
	}
	if(x.op==0)sf[p].push_back(x.r);
	else qu[p].push_back({x.id,x.r});
}
void add2(string s,int v){
	int p=1;
	for(int i=0;i<s.size();i++){
		int to=s[i]-'a';
		if(!g[p][to])g[p][to]=++gid;
		p=g[p][to];
	}
	sg[p]+=v;
}
int query(string s){
	int p=1,sum=sg[p];
	for(int i=0;i<s.size();i++){
		int to=s[i]-'a';
		if(!g[p][to])g[p][to]=++gid;
		p=g[p][to],sum+=sg[p];
	}
	return sum;
}
void dfs(int u){
	for(string x:sf[u])
		add2(x,1);
	for(pair<int,string> x:qu[u])
		ans[x.first]=query(x.second);
	for(int i=0;i<26;i++){
		if(f[u][i])
			dfs(f[u][i]);
	}
	for(string x:sf[u])
		add2(x,-1);
}
void init(){
	for(int i=1;i<=fid;i++){
		memset(f[i],0,sizeof f[i]);
		sf[i].clear(),qu[i].clear();
	}
	for(int i=1;i<=gid;i++){
		memset(g[i],0,sizeof g[i]);
		sg[i]=0;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//ÎÒµ÷²»³öÀ´°¡°¡°¡°¡CCFÄã³öÉ¶×Ö·û´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® °Å±ÈQQQQQ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ¿¾´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® ´® °¡°¡°¡°¡°¡ÎØÎØÎØÎØ 
	
	
	//ÎÒÈ¥ÁËÎÒÈ¥ÁËÖ»ÓÐ200°¡°¡°¡°¡°¡ °¡°¡°¡°¡°¡ °¡°¡°¡°¡°¡ °¡°¡°¡°¡°¡ °¡°¡°¡°¡°¡ °¡°¡°¡°¡°¡ °¡°¡°¡°¡°¡ °¡°¡°¡°¡°¡ °¡°¡°¡°¡°¡ 
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		int fi=-1,se=-1;
		for(int j=0;j<x.size();j++){
			if(x[j]!=y[j]){
				if(fi==-1)fi=j;
				se=j;
			}
		}
		if(fi==-1)continue;
		for(int j=0;j<fi;j++)
			a[i].l+=x[j];
		for(int j=fi;j<=se;j++){
			a[i].hs1=(1ll*a[i].hs1*base+x[j])%mod;
			a[i].hs1=(1ll*a[i].hs1*base+y[j]-30)%mod;
			a[i].hs2=(1ll*a[i].hs2*BASE+x[j])%MOD;
			a[i].hs2=(1ll*a[i].hs2*BASE+y[j]-30)%MOD;
		}
		for(int j=se+1;j<x.size();j++)
			a[i].r+=x[j];
		a[i].id=91;
	}
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		int id=i+n;
		if(x.size()!=y.size())continue;
		int fi=-1,se=-1;
		for(int j=0;j<x.size();j++){
			if(x[j]!=y[j]){
				if(fi==-1)fi=j;
				se=j;
			}
		}
		if(fi==-1)continue;
		for(int j=0;j<fi;j++)
			a[id].l+=x[j];
		for(int j=fi;j<=se;j++){
			a[id].hs1=(1ll*a[id].hs1*base+x[j])%mod;
			a[id].hs1=(1ll*a[id].hs1*base+y[j]-30)%mod;
			a[id].hs2=(1ll*a[id].hs2*BASE+x[j])%MOD;
			a[id].hs2=(1ll*a[id].hs2*BASE+y[j]-30)%MOD;
		}
		for(int j=se+1;j<x.size();j++)
			a[id].r+=x[j];
		a[id].id=i,a[id].op=1;
	}
	sort(a+1,a+n+q+1,cmp);
	int lst=1;
	for(int i=1;i<=n+q;i++){
		if(a[i].id==0)continue;
		if(a[i].hs1!=a[i-1].hs1||a[i].hs2!=a[i-1].hs2){
			fid=1,gid=1;
			for(int j=lst;j<i;j++){
				if(a[j].id==0)continue;
				add1(a[j]);
			}
			dfs(1),init(),lst=i;
		}
	}
	fid=1,gid=1;
	for(int j=lst;j<=n;j++){
		if(a[j].id==0)continue;
		add1(a[j]);
	}
	dfs(1),init();
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	
	return 0;
} 
