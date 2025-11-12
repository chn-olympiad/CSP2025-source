#include<bits/stdc++.h>
using namespace std;
const int N=5000015;
int n,Q,tot[2],lcq[2][N>>1],ch[2][N>>1][26],id[200005][2],dfn[2][N>>1],siz[2][N>>1],fa[2][22][N>>1],now,q[N],dep[2][N>>1],tr[N>>1];
char s[N],t[N];
vector<int>son[2][N>>1];
inline void update(int x,int y){
	for(;x<=tot[1];x+=(x&(-x)))tr[x]+=y;
}
inline int query(int x){
	int ans=0;
	for(;x;x-=(x&(-x)))ans+=tr[x];
	return ans;
}
long long ANS[200005];
inline void dfs0(int o,int x){
	siz[o][x]=1;
	dfn[o][x]=++now;
	for(int i=0;i<son[o][x].size();++i){
		int y=son[o][x][i];
		dfs0(o,y);
		siz[o][x]+=siz[o][y];
	}
}
inline int jump(int o,int x,int d){
	if(lcq[o][x]<=d)return x;
	for(int i=21;i>=0;--i){
		if(lcq[o][fa[o][i][x]]>d)x=fa[o][i][x];
	}
	return fa[o][0][x];
}
vector<pair<int,int> >ve[N>>1];
vector<int>v[N>>1];
inline void dfs(int x){
	for(int i=0;i<v[x].size();++i){
		int y=v[x][i];
		//cout<<dfn[1][y]<<' '<<dfn[1][y]+siz[1][y]-1<<' '<<1<<endl;
		update(dfn[1][y],1);
		update(dfn[1][y]+siz[1][y],-1);
	}
	for(int i=0;i<ve[x].size();++i){
		int v=query(dfn[1][ve[x][i].first]);
		int k=ve[x][i].second;
		//assert(v>=0);
		//cout<<dfn[1][ve[x][i].first]<<' '<<k<<endl;
		if(k>0)ANS[k]+=v;
		else ANS[-k]-=v;
	}
	for(int i=0;i<son[0][x].size();++i)dfs(son[0][x][i]);
	for(int i=0;i<v[x].size();++i){
		int y=v[x][i];
		//cout<<dfn[1][y]<<' '<<dfn[1][y]+siz[1][y]-1<<' '<<-1<<endl;
		update(dfn[1][y],-1);
		update(dfn[1][y]+siz[1][y],1);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&Q);
	tot[0]=tot[1]=1;
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		int len=strlen(s+1);
		int p=1;
		for(int j=1;j<=len;++j){
			if(!ch[0][p][s[j]-'a']){
				ch[0][p][s[j]-'a']=++tot[0];
				lcq[0][tot[0]]=lcq[0][p]+1;
			}
			p=ch[0][p][s[j]-'a'];
		}
		id[i][0]=p;
		scanf("%s",s+1);
		p=1;
		for(int j=1;j<=len;++j){
			if(!ch[1][p][s[j]-'a']){
				ch[1][p][s[j]-'a']=++tot[1];
				lcq[1][tot[1]]=lcq[1][p]+1;
			}
			p=ch[1][p][s[j]-'a'];
		}
		id[i][1]=p;
		v[id[i][0]].push_back(id[i][1]);
	}
	for(int o=0;o<2;++o){
		for(int i=0;i<26;++i)ch[o][0][i]=1;
		int l=1,r=1;
		q[1]=1;
		while(l<=r){
			int x=q[l++];
			//cout<<x<<endl;
			for(int i=0;i<26;++i){
				if(!ch[o][x][i]){
					ch[o][x][i]=ch[o][fa[o][0][x]][i];
				}
				else{
					q[++r]=ch[o][x][i];
					fa[o][0][ch[o][x][i]]=ch[o][fa[o][0][x]][i];
				}
			}
		}
		for(int ii=1;ii<=tot[o];++ii){
			int i=q[ii];
			dep[o][i]=dep[o][fa[o][0][i]]+1;
			son[o][fa[o][0][i]].push_back(i);
		}
		for(int i=1;i<22;++i)for(int j=1;j<=tot[o];++j)fa[o][i][j]=fa[o][i-1][fa[o][i-1][j]];
	}
	//cout<<tot[0]<<endl;
	dfs0(0,1);
	now=0;
	dfs0(1,1);
	for(int j=1;j<=Q;++j){
		scanf("%s",s+1);
		scanf("%s",t+1);
		int len=strlen(s+1),lll=strlen(t+1);
		if(len!=lll)continue;
		int l,r;
		for(int i=1;i<=len;++i)if(s[i]!=t[i]){
			l=i;
			break;
		}
		for(int i=len;i;--i)if(s[i]!=t[i]){
			r=i;
			break;
		}
		int p0=1,p1=1;
		for(int i=1;i<=len;++i){
			while(!ch[0][p0][s[i]-'a'])p0=fa[0][0][p0];
			p0=ch[0][p0][s[i]-'a'];
			while(!ch[1][p1][t[i]-'a'])p1=fa[1][0][p1];
			p1=ch[1][p1][t[i]-'a'];
			//cout<<p0<<' '<<p1<<' '<<dep[0][p0]-1<<' '<<dep[1][p1]-1<<endl;
			if(i>=r&&lcq[0][p0]>=i-l+1&&lcq[1][p1]>=i-l+1){
				int ll=i-l+1,rr=min(lcq[0][p0],lcq[1][p1]);
				//cout<<p0<<' '<<p1<<' '<<ll<<' '<<rr<<endl;
				int x=jump(0,p0,rr),y=jump(1,p1,rr);
				//cout<<x<<' '<<y<<endl;
				ve[x].push_back({y,j});
				x=jump(0,x,ll-1),y=jump(1,y,ll-1);
				//cout<<x<<' '<<y<<endl;
				ve[x].push_back({y,-j});
			}
		}
	}
	dfs(1);
	for(int i=1;i<=Q;++i)printf("%lld\n",ANS[i]);
}
