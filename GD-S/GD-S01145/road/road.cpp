#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10015],sum,ans;
struct RP{
    int u,t,v;
    friend bool operator<(const RP x,const RP y){return x.v<y.v;}
}b[2000005];
int find(int x){return (x==fa[x]?x:fa[x]=find(fa[x]));}
void add(int x,int y,int c,int &sum){
    int a=find(x),b=find(y);
    if(a!=b){
		fa[a]=b;
		sum+=c;
	}
}
void K(int n,int m,int &sum,RP b[]){
	for(int i=1;i<=n;++i)fa[i]=i;
	sort(b+1,b+1+m);
	for(int i=1;i<=m;++i)add(b[i].u,b[i].t,b[i].v,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)cin>>b[i].u>>b[i].t>>b[i].v;
    if(k==0){
    	K(n,m,sum,b);
    	cout<<sum<<'\n';
    	return 0;
	}
    for(int i=1,z;i<=k;++i){
    	cin>>z;
    	for(int j=1,t;j<=n;++j){
    		cin>>t;
    		b[++m]={i+n,j,t};
		}
    }
    K(n+k,m,sum,b);
    cout<<sum;
    return 0;
}
