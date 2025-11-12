#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 3e4+10,M = 2e6+10;
struct roa{
	int fm,to,we;
}rd[M];
int fa[N];
int c[50][N];
int n,m,k,cnt;
bool cmp(roa x,roa y){
	return x.we<y.we;
}
int find(int x){
	if(fa[x]!=x){
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
int krus(){
	int res=0,cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(rd+1,rd+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=rd[i].fm,v=rd[i].to;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			res+=rd[i].we,fa[fu]=fv,cnt++;
			if(cnt==n-1) return res;
		}
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cout<<"faker"<<endl;
	cin>>n>>m>>k;
//	cout<<"theshy"<<endl;
	for(int i=1;i<=m;i++){
//		cout<<"i="<<i<<endl;
		cin>>rd[i].fm>>rd[i].to>>rd[i].we;
	}
//	cout<<"rookie"<<endl;
	if(k==0){
		cout<<krus();
		return 0;
	}
//	cout<<"baolan"<<endl;
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			rd[(++m)].fm=(n+i),rd[m].to=j,rd[m].we=c[i][j];
		}
	}
	n=n+k;
//	cout<<"n="<<n<<" m="<<m<<endl;
	cout<<krus();
	return 0;
} 
