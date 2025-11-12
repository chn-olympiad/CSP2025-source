#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5,N=1e4+5;
struct node{
	int v,w;
};
vector<node> a[M];
int fa[N];
int n,m,k;
int cnt=0;
void add(int u,int v,int w){
	a[u].push_back({v,w});
	return;
}
bool vi[10004];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		cnt+=w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		
	}
	if(k==0){
		
		while(m>=n){
			bool f=1;
			int ma=-1,iu=0,iv=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<a[i].size();j++){
					if(a[i][j].w>ma){
						ma=a[i][j].w;
						iu=i;
						iv=a[i][j].v;
					}
				}	
			}
			// cout<<"--------------------------"<<endl;
			for(int i=1;i<=n;i++){
				for(int j=0;j<a[i].size();j++){
					if(a[i][j].v==iv){
						f=0;
						break;
					}
				}
				if(!f){
					break;
				}
			}
			//cout<<ma<<endl;
			//cout<<"--------------------------"<<endl;
			if(f==0){
				for(int j=0;j<a[iu].size();j++){
					if(a[iu][j].v==iv){
						a[iu][j].w=-1;
						a[iv][j].w=-1;
						cnt-=ma;
						m--;
						break;
					}
				}
				//cout<<"--------------------------"<<endl;
			}else{
				for(int j=0;j<a[iu].size();j++){
					if(a[iu][j].v==iv){
						a[iu][j].w=-1;
						a[iv][j].w=-1;
						m--;
						break;
					}
				}
				//cout<<"--------------------------"<<endl;
			}
		}
		//cout<<"--------------------------"<<endl;
		cout<<cnt;
		return 0;
	}
}
/*
6 7 0
1 2 1
2 3 3
2 4 7
3 4 6
1 5 5
1 6 2
4 6 2*/
