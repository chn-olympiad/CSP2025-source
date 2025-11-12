#include<bits/stdc++.h>
#define N 10005
#define M 1000005
using namespace std;

struct nod{
	int u,v,w;
};

int n,m,k;
nod a[M];

void lierr(){
	for(int j=1;j<=k;j++){
		int c;
		cin>>c;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
		}
	}
	return ;
}

int ans;

bool cmp(nod x,nod y){
	return x.w<y.w;
}

int f[N];
vector<int>s[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i]={u,v,w};
	}
	lierr();
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u=f[a[i].u],v=f[a[i].v],w=a[i].w;
		if(u==v)continue;
		ans+=w;
//		cout<<"u:"<<u<<" v:"<<v<<" w:"<<w<<" f[u]:"<<f[u]<<" f[v]:"<<f[v]<<endl;
		if(s[u].size()>s[v].size()){
			for(int j=0;j<s[v].size();j++){
//				cout<<"work "<<u<<" "<<s[v][j]<<endl;
				s[u].push_back(s[v][j]);
				f[s[v][j]]=u;
			}
//			cout<<"workkk"<<u<<" "<<v<<endl;
			s[u].push_back(v);
			f[v]=u;
			s[v].clear();
		}else{
			for(int j=0;j<s[u].size();j++){
//				cout<<"work "<<v<<" "<<s[u][j]<<endl;
				s[v].push_back(s[u][j]);
				f[s[u][j]]=v;
			}
//			cout<<"workkk"<<v<<" "<<u<<endl;
			s[v].push_back(u);
			f[u]=v;
			s[u].clear();
		}
//		for(int j=1;j<=n;j++){
//			cout<<"f["<<j<<"]="<<f[j]<<endl;
//		}
	}
	
//	for(int i=1;i<=n;i++){
//		cout<<f[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<"F:"<<i<<endl;
//		for(int j=0;j<s[i].size();j++){
//			cout<<"S:"<<s[i][j]<<endl; 
//		}
//	}
//	cout<<endl;
	
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

13
*/
