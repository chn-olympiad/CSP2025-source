#include<iostream>
#include<cstring>
#include<bitset>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
using namespace std;
typedef unsigned long long ull;
const ull inf=1e9+7,mod=998244353;
long long ans[5000005];
int n,q,tree[2][5000005],l[5000005],dep[5000005],fa[5000005][23],lgs[5000005],r[5000005],rep,len[5000005],L[5000005],W[400005],nxt[5000005][26],fail[5000005],qn,vr2,vr=1,pat[5000005],sz[5000005];
string s[200005][2],t[2];
int fr[5000005],se[5000005],nxtss[5000005];
int fr2[5000005],se2[5000005],nxtss2[5000005];
int fr3[10000005],se3[10000005],nxtss3[10000005],wt[10000005],wp[10000005],rs;
queue<int> Q;
void add(int o,int x,int k){
	while(x<=vr){
		tree[o][x]+=k;
		x+=x&-x;
	}
}
int qry(int o,int x){
	int ret=0;
	while(x){
		ret+=tree[o][x];
		x-=x&-x;
	}	
	return ret;
}
void inserts(string o,int id){
	int now=1;
	for(int i=0;i<o.size();i++){
		int cur=(int)(o[i]-'a');
		if(!nxt[now][cur]){
			nxt[now][cur]=++vr;
			len[vr]=len[now]+1;
		//	cout<<vr<<" "<<o<<" "<<i+1<<" wo "<<endl;
		}
		now=nxt[now][cur];
	}
	W[id]=now;
	if(!fr2[now]){
		fr2[now]=id;
	}
	else{
		nxtss2[se2[now]]=id;
	}
	se2[now]=id;
}
void BD(){
	fail[1]=1;
	for(int i=0;i<=25;i++){
		if(!nxt[1][i]){
			nxt[1][i]=1;
		}
		else{
			fail[nxt[1][i]]=1;
			Q.push(nxt[1][i]);
		}
	}
	while(!Q.empty()){
		int cur=Q.front();
		Q.pop();
		for(int i=0;i<=25;i++){
			if(!nxt[cur][i]){
				nxt[cur][i]=nxt[fail[cur]][i];
			}
			else{
				fail[nxt[cur][i]]=nxt[fail[cur]][i];
				Q.push(nxt[cur][i]);
			}
		}
	}
}
void BFG(){
	for(int i=2;i<=vr;i++){
		if(!fr[fail[i]]){
			fr[fail[i]]=i;
		}
		else{
			nxtss[se[fail[i]]]=i;
		}
		se[fail[i]]=i;
	}
}
void dfs(int x){
	pat[x]=++vr2;
	sz[x]=1;
	for(int i=1;i<=lgs[dep[x]];i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int i=fr[x];i;i=nxtss[i]){
		int to=i;
		dep[to]=dep[x]+1;
		fa[to][0]=x;
		dfs(to);
		sz[x]+=sz[to];
	}
}
void dfs2(int x){
	for(int i=fr2[x];i;i=nxtss2[i]){
		int ids=i;
		if(ids>=1&&ids<=n){
			rep++;
			add(0,r[W[ids+n]],1);
			add(1,l[W[ids+n]],1);
		}
	}
	for(int i=fr[x];i;i=nxtss[i]){
		int to=i;
		dfs2(to);
	}
	for(int i=fr3[x];i;i=nxtss3[i]){
		int i1,i2;
		i1=wt[i];
		i2=wp[i];
		if(i2<=n){
			ans[i2]+=(rep-qry(0,l[i1]-1)-(qry(1,vr)-qry(1,l[i1])));
		}
		else{
			ans[i2-n]-=(rep-qry(0,l[i1]-1)-(qry(1,vr)-qry(1,l[i1])));
		}
	}
	for(int i=fr2[x];i;i=nxtss2[i]){
		int ids=i;
		if(ids>=1&&ids<=n){
			rep--;
			add(0,r[W[ids+n]],-1);
			add(1,l[W[ids+n]],-1);
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		reverse(s[i][0].begin(),s[i][0].end());
		reverse(s[i][1].begin(),s[i][1].end());
		inserts(s[i][0],i);
		inserts(s[i][1],i+n);
	}
	BD();
	BFG();
	dep[1]=1;
	for(int i=2;i<=vr;i++){
		lgs[i]=lgs[i>>1]+1;
	}
	dfs(1);
	for(int i=1;i<=vr;i++){
		l[i]=pat[i];
		r[i]=pat[i]+sz[i]-1;
	}
	for(int i=1;i<=q;i++){
		cin>>t[0]>>t[1];
		int ss0=(int)(t[0].size()),ss1=(int)(t[1].size());
		if(ss0!=ss1){
			ans[i]=0;
			continue;
		}
		int nows=0,noww=ss0+1;
		for(int j=1;j<=ss0;j++){
			if(t[0][j-1]!=t[1][j-1]){
				nows=j;
			}
		}
		for(int j=ss0;j>=1;j--){
			if(t[0][j-1]!=t[1][j-1]){
				noww=j;
			}
		}
		int now=1,now2=1;
		for(int j=ss0;j>=1;j--){
			int curs=(int)(t[0][j-1]-'a'),curs2=(int)(t[1][j-1]-'a');
			now=nxt[now][curs];
			now2=nxt[now2][curs2];
			if(j<=noww){
				int ret=0,xx=now;
				for(int k=lgs[dep[xx]];k>=0;k--){
					if(len[fa[xx][k]]>=max(nows-j+1,0)){
						xx=fa[xx][k];
					}
				}/*
				for(int k=1;k<=n;k++){
					if(l[W[k]]<=l[now]&&l[now]<=r[W[k]]&&l[W[k+n]]<=l[now2]&&l[now2]<=r[W[k+n]]){
						ret++;
					//	cout<<j<<" "<<k<<endl;
					}
				}*/
				++rs;
				if(!fr3[now]){
					fr3[now]=rs;
				}
				else{
					nxtss3[se3[now]]=rs;
				}
				se3[now]=rs;
				wt[rs]=now2;
				wp[rs]=i;
				if(len[xx]>=max(nows-j+1,0)){
					xx=fa[xx][0];
				}
				++rs;
				if(!fr3[xx]){
					fr3[xx]=rs;
				}
				else{
					nxtss3[se3[xx]]=rs;
				}
				se3[xx]=rs;
				wt[rs]=now2;
				wp[rs]=i+n;
				/*
				for(int k=1;k<=n;k++){
					if(l[W[k]]<=l[xx]&&l[xx]<=r[W[k]]&&l[W[k+n]]<=l[now2]&&l[now2]<=r[W[k+n]]){
						ret--;
					//	cout<<j<<" "<<k<<endl;
					}
				}
				ans[i]+=ret;*/
				
			}
		}
	}
	dfs2(1);
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
