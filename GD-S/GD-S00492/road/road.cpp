#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,len,cnt,fat[N];
LL c[N],a[15][N],ans;
vector<pair<int,int> >g[N];
struct node{
	LL u,v,w;
}e[M*4];
bool cmp(const node& s1,const node& s2){
	return s1.w<s2.w;
}
int find(int x){
	if(fat[x]!=x)	fat[x]=find(fat[x]);
	return fat[x]; 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[++len]={u,v,w,0};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			//i-j
			LL res=1e11;
			for(int l=1;l<=k;l++){
				res=min(res,a[l][i]+a[l][j]);
			}
			e[++len]={i,j,res};
		}
	}
	for(int i=1;i<=n;i++)	fat[i]=i;
	sort(e+1,e+len+1,cmp);
	for(int i=1;i<=len;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv){
			fat[fu]=fv;
			ans+=e[i].w;
			cnt++;
		}
		if(cnt==n-1)	continue;
	}
	cout<<ans;
	return 0;
}
