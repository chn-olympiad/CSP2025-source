#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
const int M=5e6+5;
const int N=4e5+5;
typedef pair<int,int> pii;
int n,q;
char S[M],T[M];
char ss[M*2],tt[M*2];
int l[N],r[N],lp[N],rp[N];
int in1[N],de1[N],in2[N],de2[N];
int tr[M*2][26],id=1;
int dfn[M*2],siz[M*2],cnt;
void insert1(int l,int r,int wot,int x){
	int p=1;
	for(int i=l;i<=r;i++){
		//putchar(ss[i]);
		if(i==wot) de1[x]=p;
		if(!tr[p][ss[i]-'a']) tr[p][ss[i]-'a']=++id;
		p=tr[p][ss[i]-'a'];
	}
	//cout<<endl;
	in1[x]=p;
}
void insert2(int l,int r,int wot,int x){
	int p=1;
	for(int i=r;i>=l;i--){
		//putchar(tt[i]);
		if(i==wot) de2[x]=p;
		if(!tr[p][tt[i]-'a']) tr[p][tt[i]-'a']=++id;
		p=tr[p][tt[i]-'a'];
	}
	//cout<<endl;
	in2[x]=p;
}
void dfs(int u){
	dfn[u]=++cnt,siz[u]=1;
	for(int i=0;i<26;i++){
		int v=tr[u][i];
		if(v) dfs(v),siz[u]+=siz[v];
	}
}
vector<pii> ad[N*4],as[N*4];
int c[N*4];
vector<int> vec;
void add(int x,int y){
	//cout<<"add : "<<x<<" , "<<y<<endl;
	for(int i=x;i<=vec.size();i+=lowbit(i)) c[i]+=y;
}
int ask(int x){
	//cout<<"ask : "<<x<<endl;
	int res=0;
	for(int i=x;i;i-=lowbit(i)) res+=c[i];
	return res;
}
int ans[N];
int d1[N],d2[N],d3[N],d4[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	int cc=0;
	for(int i=1;i<=n;i++){
		//cout<<"ii : "<<i<<endl;
		scanf("%s",S+1),scanf("%s",T+1);
		int len=strlen(S+1);
		for(int i=1;i<=len;i++) ss[++cc]=S[i],tt[cc]=T[i];
		lp[i]=l[i]=cc-len+1,rp[i]=r[i]=cc;
		while(lp[i]<=r[i]&&ss[lp[i]]==tt[lp[i]]) lp[i]++;
		if(lp[i]==r[i]+1) continue;
		while(lp[i]<rp[i]&&ss[rp[i]]==tt[rp[i]]) rp[i]--;
		insert1(lp[i],r[i],rp[i],i);
		//cout<<l[i]<<","<<r[i]<<";"<<lp[i]<<","<<rp[i]<<endl;
	}
	for(int i=n+1;i<=q+n;i++){
		//cout<<"i : "<<i<<endl;
		scanf("%s",S+1),scanf("%s",T+1);
		int len=strlen(S+1),l2=strlen(T+1);
		if(len!=l2) continue;
		for(int i=1;i<=len;i++) ss[++cc]=S[i],tt[cc]=T[i];
		lp[i]=l[i]=cc-len+1,rp[i]=r[i]=cc;
		while(lp[i]<=r[i]&&ss[lp[i]]==tt[lp[i]]) lp[i]++;
		if(lp[i]==r[i]+1) continue;
		while(lp[i]<rp[i]&&ss[rp[i]]==tt[rp[i]]) rp[i]--;
		insert1(lp[i],r[i],rp[i],i);
	}
	//cout<<(ss+1)<<' '<<(tt+1)<<endl;
	dfs(1);
	for(int i=1;i<=n;i++){
		int p=in1[i];
		d1[i]=dfn[p],d2[i]=dfn[p]+siz[p];
	}
	for(int i=1;i<=q;i++){
		int p=in1[i+n],pp=de1[i+n];
		d1[i+n]=dfn[p],d2[i+n]=dfn[pp];
	}
	//cout<<"id : "<<id<<endl;
	for(int i=1;i<=id;i++) for(int j=0;j<26;j++) tr[i][j]=0;
	cnt=0,id=1;
	for(int i=1;i<=n+q;i++) insert2(l[i],rp[i],lp[i],i);
	//cout<<"id : "<<id<<endl;
	dfs(1);
	for(int i=1;i<=n;i++){
		int q=in2[i];
		d3[i]=dfn[q],d4[i]=dfn[q]+siz[q];
	}
	for(int i=1;i<=q;i++){
		int q=in2[i+n],qq=de2[i+n];
		d3[i+n]=dfn[q],d4[i+n]=dfn[qq];
	}
	//for(int i=1;i<=n+q;i++) cout<<d1[i]<<" , "<<d2[i]<<" , "<<d3[i]<<" , "<<d4[i]<<endl; 
	for(int i=1;i<=n+q;i++){
		vec.push_back(d1[i]),vec.push_back(d2[i]);
		vec.push_back(d3[i]),vec.push_back(d4[i]);
	}
	sort(vec.begin(),vec.end()),vec.resize(unique(vec.begin(),vec.end())-vec.begin());
	//cout<<"vec : ";for(int x:vec) cout<<x<<" ";cout<<endl;
	for(int i=1;i<=n;i++){
		int dp=lower_bound(vec.begin(),vec.end(),d1[i])-vec.begin()+1;
		int dsp=lower_bound(vec.begin(),vec.end(),d2[i])-vec.begin()+1;
		int dq=lower_bound(vec.begin(),vec.end(),d3[i])-vec.begin()+1;
		int dsq=lower_bound(vec.begin(),vec.end(),d4[i])-vec.begin()+1;
		ad[dp].push_back(make_pair(dq,1));
		ad[dp].push_back(make_pair(dsq,-1));
		ad[dsp].push_back(make_pair(dq,-1));
		ad[dsp].push_back(make_pair(dsq,1));
	}
	for(int i=1;i<=q;i++){
		int dp=lower_bound(vec.begin(),vec.end(),d1[i+n])-vec.begin()+1;
		int dpp=lower_bound(vec.begin(),vec.end(),d2[i+n])-vec.begin()+1;
		int dq=lower_bound(vec.begin(),vec.end(),d3[i+n])-vec.begin()+1;
		int dqq=lower_bound(vec.begin(),vec.end(),d4[i+n])-vec.begin()+1;
		as[dp].push_back(make_pair(dq,i));
		as[dp].push_back(make_pair(-dqq,i));
		as[dpp].push_back(make_pair(-dq,i));
		as[dpp].push_back(make_pair(dqq,i));
	}
	for(int i=1;i<=vec.size();i++){
		for(pii p:ad[i]) add(p.first,p.second);
		for(pii p:as[i]){
			if(p.first>0) /*cout<<"+",*/ans[p.second]+=ask(p.first);
			else /*cout<<"-",*/ans[p.second]-=ask(-p.first);
		}
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
/*
2 2
aa bb
a b
caab cbbb
*/
