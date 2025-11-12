/*
#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v,w;
};
struct node2{
	long long u,v,w;
};
long long n,m,k;
vector<node> s[10010];
long long x[20][10010],dp[10010][2000];
bool sf[20];
node2 bian[1000100];
long long top_bian;
bool jl[10010];
long long jiami(){
	long long num=0;
	for(int i=1;i<=k;i++){
		num<<=1;
		if(sf[i]){
			num++;
		}
	}
	return num;
}
void jiemi(long long num){
	for(int i=k;i>=1;i--){
		if(num&1){
			sf[i]=1;
		}else{
			sf[i]=0;
		}
		num>>=1;
	}
}
void dfs(long long a,long long d){
	//printf("a:%lld,d:%lld\n",a,d);
	long long maxn=pow(2,k)-1;
	long long minn[20];
	//printf("maxn:%lld\n",maxn);
	for(int i=1;i<=k;i++){
		minn[i]=1000000000000000000ll;
		
		for(int j=1;j<=n;j++){
			if(jl[j]){
				if(x[i][j]+x[i][a]+x[i][0]<minn[i]){
					minn[i]=x[i][j]+x[i][a]+x[i][0];
				}
			}
		}
		
		//printf("minn[%d]:%lld ",i,minn[i]);
	}
	for(int i=0;i<=maxn;i++){
		dp[d][i]=1000000000000000000ll;
	}
	//printf("\n");
	
	for(int j=0;j<=maxn;j++){
		//printf("\nj:%d\n",j);
		jiemi(j);
		if(j==0){
			dp[d][j]=dp[d-1][j]+bian[1].w;
			//printf("dp:%lld\n",dp[d-1][j]+bian[1].w);
			continue;
		}
		long long mi=1000000000000000000ll;
		for(int i=1;i<=k;i++){
			if(sf[i]){
				//printf("i:%d ",i);
				if(x[i][a]<mi){
					mi=x[i][a];
					//printf("mi:%lld\n",mi);
				}
			}
		}
		if(bian[1].w<mi){
			mi=bian[1].w;
			//printf("mi:%lld\n",mi);
		}
		for(int i=1;i<=k;i++){
			if(sf[i]){
				sf[i]=0;
				dp[d][j]=min(dp[d][j],dp[d-1][jiami()]+minn[i]);
				//printf("i:%d dp:%lld\n",i,dp[d-1][jiami()]+minn[i]);
				sf[i]=1;
			}
		}
		dp[d][j]=min(dp[d][j],dp[d-1][j]+mi);
		//printf("dp.mi:%lld dp:%lld\n",dp[d-1][j]+mi,dp[d][j]);
	}
	
	
	for(int i=0;i<(int)s[a].size();i++){
		if(!jl[s[a][i].v]){
			node2 tmp;
			tmp.u=a;
			tmp.v=s[a][i].v;
			tmp.w=s[a][i].w;
			for(int j=top_bian;;j--){
				if(bian[j].w<=tmp.w||j<=0){
					bian[j+1]=tmp;
					break;
				}else{
					bian[j+1]=bian[j];
				}
			}
			top_bian++;
		}
	}
	
	jl[a]=1;
	if(d>=n){
		return;
	}
	int j=0;
	
	for(int i=1;i<=top_bian;i++){
		if(!jl[bian[i].v]){
			bian[++j]=bian[i];
		}
	}
	
	top_bian=j;
	dfs(bian[1].v,d+1);
}
int main(){
	freopen("road2.in","r",stdin);
	freopen("road2.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		node tmp;
		tmp.v=v;
		tmp.w=w;
		s[u].push_back(tmp);
		tmp.v=u;
		s[v].push_back(tmp);
	}
	for(int i=1;i<=k;i++){
		cin>>x[i][0];
		for(int j=1;j<=n;j++){
			cin>>x[i][j];
		}
	}
	jl[1]=1;
	for(int i=0;i<(int)s[1].size();i++){
		node2 tmp;
		tmp.u=1;
		tmp.v=s[1][i].v;
		tmp.w=s[1][i].w;
		bian[1]=tmp;
		top_bian++;
	}
	long long maxn=pow(2,k)-1;
	for(int j=1;j<=maxn;j++){
		dp[1][j]=1000000000000000000ll;
	}
	dfs(bian[1].v,2);
	long long ans=1000000000000000000ll;
	for(int j=0;j<=maxn;j++){
		ans=min(ans,dp[n][j]);
	}
	cout<<ans;
	return 0;
	
}
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v,w;
};
struct node2{
	long long u,v,w;
};
long long n,m,k;
vector<node> s[10010];
long long x[20][10000010];
long long fa[10000010];
node2 bian[10000010];
long long top=0;
bool cmp(node2 a,node2 b){
	return a.w<b.w;
}
long long search(long long a){
	if(fa[a]==a){
		return a;
	}
	fa[a]=search(fa[a]);
	return fa[a];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		node tmp;
		tmp.v=v;
		tmp.w=w;
		s[u].push_back(tmp);
		tmp.v=u;
		s[v].push_back(tmp);
		node2 tmpp;
		tmpp.u=u;
		tmpp.v=v;
		tmpp.w=w;
		bian[++top]=tmpp;
		cout<<bian[top].u<<" "<<bian[top].v<<endl;
	}
	for(int i=1;i<=k;i++){
		cin>>x[i][0];
		long long bb;
		for(int j=1;j<=n;j++){
			cin>>x[i][j];
			if(x[i][j]==0){
				bb=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(j!=bb){
				node tmp;
				tmp.v=j;
				tmp.w=x[i][j];
				s[bb].push_back(tmp);
				tmp.v=bb;
				s[j].push_back(tmp);
				node2 tmpp;
				tmpp.u=bb;
				tmpp.v=j;
				tmpp.w=x[i][j];
				bian[++top]=tmpp;
				cout<<bian[top].u<<" "<<bian[top].v<<" "<<bian[top].w<<endl;
			}
		}
	}
	sort(bian+1,bian+top+1,cmp);
	long long sum=0,ans=0;
	
	for(int i=1;sum<n-1;i++){
		//cout<<bian[i].u<<" "<<bian[i].v<<endl;
		//cout<<search(bian[i].u)<<" "<<search(bian[i].v)<<endl;
		if(search(bian[i].u)==search(bian[i].v)){
		//if(bian[i].u==bian[i].v){
			continue;
		}else{
			fa[bian[i].u]=bian[i].v;
			ans+=bian[i].w;
			sum++;
		}
	}
	
	cout<<ans;
	return 0;
	
}
/*
6 9 1
1 2 3
2 3 5
3 4 2
4 5 1
5 6 2
1 6 4
1 4 3
2 4 4
3 6 6
0 10 0 10 1 10 10
*/
