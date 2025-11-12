#include<bits/stdc++.h> 
using namespace std;
namespace MYQ{
	int n,m,rt[500001],so[6000001][27],cnt,ct,ne[200001],h[6000001],nx[200001],ans[200001],qne[200001],qh[6000001],qnx[200001],L[6000001],R[6000001],cct,d[6000001];
	char s[2][5000001];
	unordered_map<long long,int>q[2];
	int ins(int x,bool k,int l,int r){
		if(l>r)
			return x;
		if(so[x][s[k][l]-'a']==0)
			so[x][s[k][l]-'a']=++ct;
		return ins(so[x][s[k][l]-'a'],k,l+1,r);
	}
	int ch(int x,bool k,int l,int r,bool bo){
		if(l>r)
			return x;
		if(so[x][s[k][l]-'a']==0){
			if(bo==0)
				return 0;
			return x;
		}
		return ch(so[x][s[k][l]-'a'],k,l+1,r,bo);
	}
	void dfs1(int x){
		L[x]=++cct;
		for(int i=0;i<26;i++)
			if(so[x][i]!=0)
				dfs1(so[x][i]);
		R[x]=cct;
	}
	inline void xg(int x,int y){
		for(int i=x;i<=cct;i+=(i&-i))
			d[i]+=y;
	}
	inline int ch(int x){
		int an=0;
		for(int i=x;i>0;i-=(i&-i))
			an+=d[i];
		return an;
	}
	void dfs2(int x){
		for(int i=h[x];i!=0;i=ne[i]){
			xg(L[nx[i]],1);
			xg(R[nx[i]]+1,-1);
		}
		for(int i=qh[x];i!=0;i=qne[i])
			ans[i]=ch(L[qnx[i]]);
		for(int i=0;i<26;i++)
			if(so[x][i]!=0)
				dfs2(so[x][i]);
		for(int i=h[x];i!=0;i=ne[i]){
			xg(L[nx[i]],-1);
			xg(R[nx[i]]+1,1);
		}
	}
	int main(){
		scanf("%d%d",&n,&m);
		cnt=1;
		ct=2;
		rt[0]=1,rt[1]=2;
		for(int i=1;i<=n;i++){
			scanf("%s%s",s[0],s[1]);
			int le=strlen(s[0]);
			int l=le,r=-1;
			for(int j=0;j<le;j++)
				if(s[0][j]!=s[1][j]){
					if(l==le)
						l=j;
					r=j;
				}
			if(l==le){
				n--,i--;
				continue;
			}
			int x=ins(rt[0],0,l,r);
			int y=ins(rt[1],1,l,r);
			if(q[0][(long long)(x)<<30ll|y]==0){
				q[0][(long long)(x)<<30ll|y]=++cnt;
				rt[cnt]=++ct;
				q[1][(long long)(x)<<30ll|y]=++cnt;
				rt[cnt]=++ct;
			}
//			if(q[0][(long long)(x)<<30ll|y]==202)
//				printf("%s\n%s\n%d %d  %d %d\n\n",s[0],s[1],x,y,l,r);
			reverse(s[0],s[0]+l);
			int xx=ins(rt[q[0][(long long)(x)<<30ll|y]],0,0,l-1);
			nx[i]=ins(rt[q[1][(long long)(x)<<30ll|y]],0,r+1,le-1);
			ne[i]=h[xx];
			h[xx]=i;
		}
		for(int i=1;i<=m;i++){
			scanf("%s%s",s[0],s[1]);
			int le=strlen(s[0]);
			if(le!=(int)strlen(s[1]))
				continue;
			int l=le,r=-1;
			for(int j=0;j<le;j++)
				if(s[0][j]!=s[1][j]){
					if(l==le)
						l=j;
					r=j;
				}
//			printf("%d %d\n",l,r);
			int x=ch(rt[0],0,l,r,0);
			int y=ch(rt[1],1,l,r,0);
			if(q[0][(long long)(x)<<30ll|y]==0)
				continue;
			reverse(s[0],s[0]+l);
			int xx=ch(rt[q[0][(long long)(x)<<30ll|y]],0,0,l-1,1);
			qnx[i]=ch(rt[q[1][(long long)(x)<<30ll|y]],0,r+1,le-1,1);
//			printf("%d %d\n",xx,qnx[i]);
			qne[i]=qh[xx];
			qh[xx]=i;
		}
		for(int i=2;i<=cnt;i+=2){
			cct=0;
			dfs1(rt[i+1]);
			dfs2(rt[i]);
		}
		for(int i=1;i<=m;i++)
			printf("%d\n",ans[i]);
		return 0;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	MYQ::main();
	return 0;
}
