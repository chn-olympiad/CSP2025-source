#include<bits/stdc++.h>
using namespace std;
#define file
#define infile "road.in"
#define outfile "road.out"

#ifdef file
#define cin ___cin___
#define cout ___cout___
ifstream ___cin___(infile);
ofstream ___cout___(outfile);
#endif

int n,m,k;
long long ans = 0;

vector<vector<unsigned long long>>img;

unsigned long long min(unsigned long long a,unsigned long long b){
	if(a<b){
		return a;
	}
	return b;
}

int main(){
	cin>>n>>m>>k;
	img.resize(n+5,vector<unsigned long long>(n+5,0));
	for(int i = 0;i < m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(u!=v){
			if(img[u][v]!=0){
				img[u][v] = img[v][u] = min(img[u][v],w);
			}else{
				img[u][v] = img[v][u] = w;
			}
		}
	}
	for(int i = 0;i < k;i++){
		for(int j = 0;j <= n;j++){
			int t;
			cin>>t;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			ans+=img[i][j];
		}
	}
	ans/=2;
	cout<<ans;
	return 0;
}

