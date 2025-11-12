#include<bits/stdc++.h>
using namespace std;
int read(){
	int x,c;
	while((c=getchar())<'0'||c>'9');
	x=c^48;
	while((c=getchar())>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48);
	return x;
}
int readstring(char *str){
	while((*str=getchar())<'a'||*str>'z');
	int len=1;
	while((*(++str)=getchar())>='a'&&*str<='z')len++;
	*str=0;
	return len;
}
const int maxn=200020;
const int node=11000000;
char s1[5000020],s2[5000020];
const int rep[26][2]={
	{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},
	{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},
	{2,0},{2,1},{2,2},{2,3},{2,4},{2,5},
	{3,0},{3,1},{3,2},{3,3},{3,4},{3,5},
	{4,0},{4,1}};
int ch[node][6],sl[node],sr[node],tot=1,qmb=0;
int va[maxn],vb[maxn],qa[maxn],qb[maxn],ans[maxn];
void dfs2(int p){
	sl[p]=qmb+1;qmb+=sr[p];
	for(int i=0;i<6;i++)
		if(ch[p][i])
			dfs2(ch[p][i]);
	sr[p]=qmb;
}
void dfs1(int p){
	if(sl[p]){
		dfs2(sl[p]);
		dfs2(sr[p]);
	}
	for(int i=0;i<6;i++)
		if(ch[p][i])
			dfs1(ch[p][i]);
}
struct Change{
	int tim,pos,typ;
	Change(){}
	Change(int _tim,int _pos,int _typ){tim=_tim;pos=_pos;typ=_typ;}
	bool operator<(const Change &x){
		if(tim==x.tim)return typ<x.typ;
		return tim<x.tim;
	}
};
vector<Change> qd;
int c[maxn<<2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read(),x,p,a,b;
	for(int i=1;i<=n;i++){
		x=readstring(s1);
		x=readstring(s2);
		a=b=-1;
		for(int j=0;j<x;j++)
			if(s1[j]!=s2[j])
				{a=j;break;}
		if(a==-1){i--;n--;continue;}
		for(int j=x-1;j>=0;j--)
			if(s1[j]!=s2[j])
				{b=j;break;}
		p=1;
		for(int j=a;j<=b;j++){
			for(int k=0;k<2;k++){
				int &u=ch[p][rep[s1[j]-97][k]];
				if(u==0)u=++tot;
				p=u;
			}
			for(int k=0;k<2;k++){
				int &u=ch[p][rep[s2[j]-97][k]];
				if(u==0)u=++tot;
				p=u;
			}
		}
		if(sl[p]==0)
			{sl[p]=++tot;sr[p]=++tot;}
		va[i]=sl[p];
		for(int j=a-1;j>=0;j--)
			for(int k=0;k<2;k++){
				int &u=ch[va[i]][rep[s1[j]-97][k]];
				if(u==0)u=++tot;
				va[i]=u;
			}
		vb[i]=sr[p];
		for(int j=b+1;j<x;j++)
			for(int k=0;k<2;k++){
				int &u=ch[vb[i]][rep[s1[j]-97][k]];
				if(u==0)u=++tot;
				vb[i]=u;
			}
		sr[va[i]]=1;sr[vb[i]]=1;
	}
	for(int i=1;i<=q;i++){
		x=readstring(s1);
		if(x!=readstring(s2))
			continue;
		for(int j=0;j<x;j++)
			if(s1[j]!=s2[j])
				{a=j;break;}
		for(int j=x-1;j>=0;j--)
			if(s1[j]!=s2[j])
				{b=j;break;}
		p=1;
		for(int j=a;j<=b;j++){
			for(int k=0;k<2;k++){
				int &u=ch[p][rep[s1[j]-97][k]];
				p=u;
			}
			if(p==0)break;
			for(int k=0;k<2;k++){
				int &u=ch[p][rep[s2[j]-97][k]];
				p=u;
			}
			if(p==0)break;
		}
		if(sl[p]==0)
			continue;
		qa[i]=sl[p];
		for(int j=a-1;j>=0;j--){
			bool fd=false;
			for(int k=0;k<2;k++){
				int &u=ch[qa[i]][rep[s1[j]-97][k]];
				if(u==0){fd=true;break;}
				qa[i]=u;
			}
			if(fd)break;
		}
		qb[i]=sr[p];
		for(int j=b+1;j<x;j++){
			bool fd=false;
			for(int k=0;k<2;k++){
				int &u=ch[qb[i]][rep[s1[j]-97][k]];
				if(u==0){fd=true;break;}
				qb[i]=u;
			}
			if(fd)break;
		}
		sr[qa[i]]=1;sr[qb[i]]=1;
	}
	dfs1(1);
	for(int i=1;i<=n;i++){
		qd.emplace_back(sl[va[i]],sl[vb[i]],-1);
		qd.emplace_back(sr[va[i]]+1,sr[vb[i]]+1,-1);
		qd.emplace_back(sl[va[i]],sr[vb[i]]+1,-2);
		qd.emplace_back(sr[va[i]]+1,sl[vb[i]],-2);
	}
	for(int i=1;i<=q;i++)
		if(qa[i])
			qd.emplace_back(sl[qa[i]],sl[qb[i]],i);
	sort(qd.begin(),qd.end());
	for(auto &i:qd)
		if(i.typ==-1){
			x=i.pos;
			while(x<=qmb){
				c[x]++;
				x+=x&-x;
			}
		}
		else if(i.typ==-2){
			x=i.pos;
			while(x<=qmb){
				c[x]--;
				x+=x&-x;
			}
		}
		else{
			x=i.pos;
			while(x>0){
				ans[i.typ]+=c[x];
				x-=x&-x;
			}
		}
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}