#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
struct node{
	long long u,v,w;
}E[N];
long long a[11][N],fa[N],n,m,k;
inline bool cmp(node x,node y){
	return x.w<y.w;
}
inline long long find(long long x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>E[i].u>>E[i].v>>E[i].w;
	}
	bool isA=true;
	for(long long i=1;i<=k;i++){
		cin>>a[i][0];
		if(a[i][0]!=0) isA=false;
		for(long long j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) isA=false;
		}
	}
	if(isA==true){
		cout<<"0"<<endl;
		return 0;
	}
	long long ans=1e16;
	for(long long sta=0;sta<=(1<<k)-1;sta++){
		vector<node>edg;
		for(long long i=1;i<=m;i++) edg.push_back((node){E[i].u,E[i].v,E[i].w});
		long long tmpm=m,tans=0,num=0;
		for(long long i=1;i<=k;i++){
			if((1<<(i-1))&sta){
				num++;
				tans+=a[i][0];
				for(long long j=1;j<=n;j++){
					for(long long p=1;p<=n;p++){
						tmpm++;
						edg.push_back((node){j,p,a[i][j]+a[i][p]});
					}
				}
			}
		}
		//cout<<num<<endl;
		for(long long i=1;i<=n+k;i++) fa[i]=i;
		sort(edg.begin(),edg.end(),cmp);
		//for(long long i=0;i<tmpm;i++) cout<<edg[i].w<<" ";
		//cout<<endl;
		long long tot=0;
		for(long long i=0;i<tmpm;i++){
			if(find(edg[i].u)!=find(edg[i].v)){
				fa[find(edg[i].u)]=find(edg[i].v);
				tans+=edg[i].w,tot++;
				if(tot==n-1) break;
			}
		}
		ans=min(ans,tans);
		//cout<<"sta:"<<sta<<" tans:"<<tans<<" ans:"<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
