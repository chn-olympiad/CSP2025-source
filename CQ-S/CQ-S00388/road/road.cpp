#include <bits/stdc++.h>
const int N=1e4+7,M=1100007;
using namespace std;
int n,m,k,len,father[M],Pre[M],Next[M],eg[11][N],firstside=1,c[N],cn;
bool mark[17];
struct Edge{
	int x;
	int y;
	int z;
}edge[M];
long long res=0x3f3f3f3f3f3f3f3f;
int getfather(int x){
	return (father[x]==x)?x:father[x]=getfather(father[x]);
}
bool cmp(Edge a,Edge b){
	return a.z<b.z;
}
int bin_search1(int l,int r,int x){
	++r;
	while(l<r){
		int mid=l+r>>1;
		if(edge[mid].z>=x) r=mid;
		else l=mid+1;
	}
	return l;
}
int bin_search2(int l,int r,int x){
	++r;
	while(l<r){
		int mid=l+r>>1;
		if(edge[mid].z>x) r=mid;
		else l=mid+1;
	}
	return l;
}
void init(){
	sort(edge+1,edge+1+m,cmp);
	for(int i=1; i<m; ++i){
		Next[i]=i+1;
		Pre[i+1]=i;
	}
	len=m;
}
void update(int x,int p,int op){//op=1表示将x加在p后面，否则表示加在p前面 
	if(op==1){
		Pre[Next[p]]=x;
		Next[x]=Next[p];
		Next[p]=x;
		Pre[x]=p;
	}
	else{
		if(firstside==p){
		    firstside=x;
		}
		Next[Pre[p]]=x;
		Pre[x]=Pre[p];
		Pre[p]=x;
		Next[x]=p;
	}
}
void earse(int x){
	--len;
    if(firstside==x) firstside=Next[firstside];
    Next[Pre[x]]=Next[x];
    Pre[Next[x]]=Pre[x];
}
void Kruskal(long long ans){
	for(int i=1; i<=n; ++i){
		father[i]=i;
	}
	int cnt=0;
	for(int i=firstside; i&&cnt<n-1; i=Next[i]){
//		cout<<i<<endl;
//cout<<"edge["<<i<<"].x"<<edge[i].x<<endl;
		int fx=getfather(edge[i].x),fy=getfather(edge[i].y);
//		cout<<i<<endl;
		if(fx!=fy){
		    father[fy]=fx;
		    ans+=edge[i].z;
			++cnt;
//			cout<<edge[i].x<<edge[i].y<<endl;
		}
	}
	res=min(res,ans);
}
void dfs(int depth){
	if(depth==k+1){
		long long ans=0;
		for(int i=1; i<=k; ++i){
			if(mark[i]==1) ans+=c[i];
		}
		Kruskal(ans);
	    return;
	}
	int u=len+1;
	++n;
	for(int i=1; i<=cn; ++i){
//		cout<<"eg["<<depth<<"]["<<i<<"]"<<eg[depth][i]<<endl;
		int ne=bin_search2(1,len,eg[depth][i]),pr=bin_search1(1,len,eg[depth][i]);
//		cout<<"ne: "<<ne<<"    pr:"<<pr<<"  edg"<<eg[depth][i]<<endl;
		if(ne>len) update(++len,pr,1);
		else update(++len,ne,0);
		edge[len].x=cn+depth,edge[len].y=i,edge[len].z=eg[depth][i];
	}
	mark[depth]=1;
	dfs(depth+1);
	mark[depth]=0;
	--n;
	for(int i=u; i<=u+cn-1; ++i){
	    earse(i);
	}
	dfs(depth+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    cn=n;
    for(int i=1; i<=m; ++i){
    	cin>>edge[i].x>>edge[i].y>>edge[i].z;
	}
	for(int i=1; i<=k; ++i){
		cin>>c[i];
		for(int j=1; j<=n; ++j){
	 	    cin>>eg[i][j];
//	 	    cout<<"eg["<<i<<"]["<<j<<"] = "<<eg[i][j]<<endl;
//	 	    if(eg[i][j]==0) cout<<"?!?!"<<endl;
	    }
	}
	init();
	Kruskal(0);
	dfs(1);
	cout<<res;
	return 0;
}
/*
xian zai shi bei jing shi jian 18:12
gan jue zhe si ge xiao shi xie chu de san fen dai ma ke neng shi wo liang nian OI de dian feng le 
A ti neng qie , wo hai ting gao xing de
B ti xie le you shi yi lai zui chang de dai ma,bu guo da gai zhi neng guo k<=5 de dian
(zhe dou you dian xuan,yang li 2 ben ti pao le 1.3s xi wang CCF ping ce ji gei li dian)
D ti zhi neng da bao sou le
tan xin,bing cha ji,sou suo
zhe shi wo zai -S zhong yong dao de suan fa(shu ju jie gou)
yi zhi dao shang zhou hai zai si ke xian duan shu,zui hou hai shi mei yong shang
mo ni sai zha guo hen duo ci
dan gan jue zhe ci zhuang tai yao bi mo ni sai hao hen duo
sui ran zong shi zai zhu bie ren rp++ , dan wo you he chang bu xiang yao 1= ne
ai 1= zhong jiu zhi shi yi ge meng ba le
dan ru guo zhe ci kao zha jiu zhen de yao tui yi le
a xie wan le xian zai shi bei jing shi jian 18:26 , ju li kao shi jie shu hai sheng 4min
zhu wo hao yun ba
by luogu uid 1272956
*/
