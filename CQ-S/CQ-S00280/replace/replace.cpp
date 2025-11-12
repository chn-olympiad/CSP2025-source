#include<bits/stdc++.h>
using namespace std;
int aaaaa;
int bh[200007],b[5000007],b1[5000007],le[5000007],js,n,m,k,l,bi[5000006],cnt,k1[5000006],k2[5000007],k3[5000007],cnt1,cnt2,cd,df[5000006],dfn,si[5000007],an[200007],fa[5000007],fa1[5000007],c1[10000007],c2[10000007],c3[10000007],cn,mo[5000006];
vector<int>ve[5000007],ve1[5000007];
int so[5000007][27],go[5000007][27];
string st1[200007],st2[200007],sr1[200007],sr2[200007];
int bbbbb;
void DD(int x,int y){
	k1[++cd]=k2[x];
	k2[x]=cd;
	k3[cd]=y;
}
int lb(int x){return x&-x;}
void X(int x,int y){for(int j=x;j<=dfn;j+=lb(j))bi[j]+=y;}
long long Q(int x){
	long long ans=0;
	for(int j=x;j>=1;j-=lb(j))ans+=bi[j];
	return ans;
}
void B(int ty){
	int cnt=ty==1?cnt1:cnt2;
	for(int i=0;i<=cnt;i++){
		int x=b[i];
		if(x){
			fa[x]=go[fa1[x]][mo[x]];
			for(int j=0;j<=25;j++){
				go[x][j]=so[fa[x]][j]?so[fa[x]][j]:go[fa[x]][j];
			}
		}
		for(int j=0;j<=25;j++)if(so[x][j])b[++js]=so[x][j];
	}
	js=0;
}
void dfs(int x,int y){
	df[y]=++dfn;si[y]=1;
	//cout<<x<<' '<<y<<' '<<go[fa[3]][2]<<' '<<go[7][2]<<'\n';
	for(int j=k2[y];j;j=k1[j]){
		int tt=k3[j];
		if(tt!=x){
			dfs(y,tt);
			si[y]+=si[tt];
		}
	}
}
void dfa(int x,int y){
	b[++js]=y,b1[js]=le[y];
	for(int tt:ve1[y]){
		X(df[bh[tt]],1);
		X(df[bh[tt]]+si[bh[tt]],-1);
		//cout<<df[bh[tt]]<<' '<<df[bh[tt]]+si[bh[tt]]-1<<"+++++++++"<<'\n';
	}
	for(int tt:ve[y]){
		
		if(b1[js]<c3[tt])c3[tt]=0;
		else{
			
			int lc=lower_bound(b1+1,b1+js+1,c3[tt])-b1-1;
			if(lc){
				//cout<<c1[tt]<<' '<<b[lc]<<' '<<le[b[lc]]<<'\n';
				++cn;
				c1[cn]=c1[tt];c2[cn]=c2[tt];
				c3[cn]=-1;
				//if(c2[tt]==1)cout<<c1[tt]<<' '<<c3[tt]<<' '<<b1[js]<<' '<<b[lc]<<' '<<b1[lc]<<'\n';
				ve[b[lc]].push_back(cn);
			}
			c3[tt]=1;
		}
	}
	for(int j=k2[y];j;j=k1[j]){
		int tt=k3[j];
		if(tt!=x)dfa(y,tt);
	}
	for(int tt:ve[y]){
		an[c2[tt]]+=Q(df[c1[tt]])*c3[tt];
		//if(c2[tt]==1)cout<<Q(df[c1[tt]])<<' '<<c1[tt]<<' '<<df[c1[tt]]<<' '<<cnt1<<'\n';
	}
	for(int tt:ve1[y]){
		X(df[bh[tt]],-1);
		X(df[bh[tt]]+si[bh[tt]],1);
		//cout<<df[bh[tt]]<<' '<<df[bh[tt]]+si[bh[tt]]-1<<"----------"<<'\n';
	}
	--js;
}
int main(){
//	cerr<<(double)(&aaaaa-&bbbbb)/6e7*256<<'\n';
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>st1[i]>>st2[i];int ts=0;
		for(int j=0;j<(int)st1[i].size();j++){
			if(!so[ts][st1[i][j]-'a'])so[ts][st1[i][j]-'a']=++cnt1,fa1[cnt1]=ts,mo[cnt1]=st1[i][j]-'a';
			ts=so[ts][st1[i][j]-'a'];
		}
		bh[i]=ts;	
	}
	cn=0;
	B(1);
	for(int i=1;i<=m;i++){
		cin>>sr1[i]>>sr2[i];
		if(sr1[i].size()!=sr2[i].size()){
			an[i]=0;
			continue;
		}
		int ts=0;
		int tk1=0,tk2=sr1[i].size()-1;
		while(sr1[i][tk1]==sr2[i][tk1])++tk1;
		while(sr1[i][tk2]==sr2[i][tk2])--tk2;
		//cout<<i<<' '<<tk1<<' '<<tk2<<' '<<sr1[i][sr1[i].size()-1]<<'\n';
		for(int j=0;j<(int)sr1[i].size();j++){
			int qt=ts;
			ts=so[ts][sr1[i][j]-'a'];
			if(!ts)ts=go[qt][sr1[i][j]-'a'];
			//cout<<i<<' '<<ts<<' '<<fa[ts]<<' '<<go[10][0]<<'\n';
			if(j>=tk2){
				
				c1[++cn]=ts;c2[cn]=i;
				c3[cn]=j-tk1+1;
			}
		}
	}
	//cout<<so[0][1]<<'\n';
	for(int i=1;i<=cnt1;i++)DD(fa[i],i);
	dfs(0,0);cd=0;
	//cout<<df[4]<<'\n';
	for(int i=0;i<=cnt1;i++){
		k2[i]=0;
		for(int j=0;j<=25;j++)so[i][j]=0;
	}
	
	for(int i=1;i<=n;i++){
		int ts=0;
		for(int j=0;j<(int)st2[i].size();j++){
			if(!so[ts][st2[i][j]-'a'])so[ts][st2[i][j]-'a']=++cnt2,fa1[cnt2]=ts,mo[cnt2]=st2[i][j]-'a',le[cnt2]=le[ts]+1;
			ts=so[ts][st2[i][j]-'a'];
			//cout<<i<<' '<<ts<<'\n';
		}
		ve1[ts].push_back(i);
	}
	B(2);
	for(int i=1;i<=cnt2;i++)DD(fa[i],i);
	cn=0;
	for(int i=1;i<=m;i++){
		if(sr1[i].size()!=sr2[i].size())continue;
		int ts=0;
		int tk1=0,tk2=sr1[i].size()-1;
		while(sr1[i][tk1]==sr2[i][tk1])++tk1;
		while(sr1[i][tk2]==sr2[i][tk2])--tk2;
		for(int j=0;j<(int)sr2[i].size();j++){
			int qt=ts;	
			ts=so[ts][sr2[i][j]-'a'];
			if(!ts)ts=go[qt][sr2[i][j]-'a'];
			if(j>=tk2){
				++cn;
				//if(i==1)cout<<ts<<'\n';
				ve[ts].push_back(cn);
			}
			
		}
	}
	dfa(0,0);
	for(int i=1;i<=m;i++)cout<<an[i]<<'\n';
}
