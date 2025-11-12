#include<bits/stdc++.h>
using namespace std;
long long vlu[10005][10005];
long long tu[10005][10005];
long long n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	map<long long,vector<long long>>du;
	long long sum=0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tu[i][j]=LLONG_MAX;
		}
	}
	for(int i=0;i<n;i++){
		vlu[i][i]=0;
	}
	
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		tu[u][v]=w;
		tu[v][u]=w;
		du[u].push_back(v);
		du[v].push_back(u);
		vlu[u][v]=w;
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<m;i++){
			for(auto a : du[i]){
				if(i==j){
					continue;
				}
				if(tu[j][i]!=LLONG_MAX){
					vlu[j][i]=min(tu[j][i]+tu[i][a],vlu[j][i]);
					if(vlu[j][i]==tu[j][i]+tu[i][a]){
						tu[j][a]=tu[j][i]+tu[i][a];
					}
				}
			}
		}
	}
	for(int i=0;i<k;i++){
		long long c;
		vector<long long>a(n);
		cin>>c;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int op=0;op<n;op++){
			for(int o=0;o<n;o++){
				vlu[op][o]=min(c+a[op-1]+a[o-1],vlu[op][o]);
			}
		}
	}
	for(int j=1;j<n;j++){
		for(int i=1;i<=n;i++){
			sum+=vlu[j][i];
		}	
	}
	cout<<sum;
	return 0;
}