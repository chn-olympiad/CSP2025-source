#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=4e5+5,M=5e6+5;
struct node{ull num;int id,l,r;}t[N];
int tr[M][27],sz[M],idx,fail[M],n,Q,ans[N],tp[M],deg[M];
string str[N][2];
bool cmp(node A,node B){return A.num<B.num;}
void init(){
	for(int i=0;i<=26;++i)
		for(int j=0;j<=idx;++j)
			tr[j][i]=0;
	for(int i=0;i<=idx;++i)
		sz[i]=fail[i]=deg[i]=tp[i]=0;
	idx=0;
}
void insert(int id){
	int p=t[id].id,nw(0);
	for(int i=0;i<str[p][0].size();++i){
		if(i==t[id].l){
			i=t[id].r;
			if(!tr[nw][26])tr[nw][26]=++idx;
			nw=tr[nw][26];
			continue;
		}
		int o=str[p][0][i]-'a';
		if(!tr[nw][o])
			tr[nw][o]=++idx;
		nw=tr[nw][o];
	}
	++sz[nw];
}
void Get_fail(){
	queue<int>q;
	for(int i=0;i<27;++i)
		if(tr[0][i])q.push(tr[0][i]);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<27;++i){
			if(tr[u][i]){
				fail[tr[u][i]]=tr[fail[u]][i];
				deg[fail[tr[u][i]]]++;
				q.push(tr[u][i]);
			}
			else tr[u][i]=tr[fail[u]][i];
		}
	}
	for(int i=1;i<=idx;++i)
		if(!deg[i])q.push(i);
	int ord(0);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		tp[++ord]=u;
		if(!fail[u])continue;
		if(!--deg[fail[u]])q.push(fail[u]);
	}
	for(int i=idx;i;--i)
		sz[tp[i]]+=sz[fail[tp[i]]];
}
int find(int id){
	int p=t[id].id,nw(0),res=sz[0];
	for(int i=0;i<str[p][0].size();++i){
		if(i==t[id].l){
			i=t[id].r;
//			if(!tr[nw][26])break;
			nw=tr[nw][26];
			res+=sz[nw];
			continue;
		}
		int o=str[p][0][i]-'a';
//		if(!tr[nw][o])break;
		nw=tr[nw][o];
		res+=sz[nw];
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>str[i][0]>>str[i][1];
		if(str[i][0]==str[i][1]){
			t[i].id=1e9;
			continue;
		}
		int sz=str[i][0].size();
		int l(0),r(sz-1);
		while(str[i][0][l]==str[i][1][l])++l;
		while(str[i][0][r]==str[i][1][r])--r;
		ull nw(0);
		for(int j=l;j<=r;++j)
			nw=nw*29+(str[i][0][j]-'a'+1);
		for(int j=l;j<=r;++j)
			nw=nw*29+(str[i][1][j]-'a'+1);
		t[i]={nw,i,l,r};
//		printf("%lld %d %d\n",nw,l,r);
	}
	for(int i=n+1;i<=n+Q;++i){
		cin>>str[i][0]>>str[i][1];
		int sz=str[i][0].size();
		if(sz!=str[i][1].size()){
			t[i].id=1e9;
			continue;
		}
		int l(0),r(sz-1);
		while(str[i][0][l]==str[i][1][l])++l;
		while(str[i][0][r]==str[i][1][r])--r;
		ull nw(0);
		for(int j=l;j<=r;++j)
			nw=nw*29+(str[i][0][j]-'a'+1);
		for(int j=l;j<=r;++j)
			nw=nw*29+(str[i][1][j]-'a'+1);
		t[i]={nw,i,l,r};
//		printf("%lld %d %d\n",nw,l,r);
	}
	sort(t+1,t+1+(n+Q),cmp);
	for(int i=1,j=1;i<=n+Q;i=j+1,j=i){
		if(t[i].id>=1e9)continue;
		init();
		if(t[i].id<=n)insert(i);
		while(j<n+Q&&t[j+1].num==t[i].num){
			++j;
			if(t[j].id<=n)insert(j);
		}
//		puts("-1");
		Get_fail();
//		puts("-1");
		for(int k=i;k<=j;++k)
			if(t[k].id>n&&t[k].id<1e9)ans[t[k].id]=find(k);
	}
	for(int i=n+1;i<=n+Q;++i)
		cout<<ans[i]<<endl;
	return 0;
} 
