#include<bits/stdc++.h>
using namespace std;
struct tpair{
	int first,second,third;
	friend bool operator<(tpair a,tpair b){
		if(a.first<b.first)return 1;
		if(a.first>b.first)return 0;
		return a.second < b.second;
	}
};
/*
unordered_map<pair<int,int>,bool> conect;
pair<int,int> index[1000003];*/
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	int w[m+7]; 
	int a[k+3][n+4];
	tpair uvw[m+7];
	for(int i = 0;i<m;++i){
		cin>>uvw[i].first>>uvw[i].second>>uvw[i].third;
		if(uvw[i].first>uvw[i].second)swap(uvw[i].first,uvw[i].second);
	}
	int c[k+3];
	for(int i = 0;i<k;++i){
		cin>>c[i];
		for(int j = 0;j<n;++j)cin>>a[i][j];
	}
	
	/*if(k==0){
		sort(uvw,uvw+m);
		for(int i = 1;i<=n-1){
			for(int j = 0;j<m;++j){
				if(uvw[j].first==i){
					if(index[i].first==0){
						index[i].first=j;
					}
					else {
						index[i].second=j;
					}
				}
			}
		}
		unsigned long long ans = 0;
		for(int i = 1;i<=n;++i){
			for(int j = index[i].first;j<=index[i].second;++j){
				int other = uvw[j].second;
				if(conect[make_pair(i,other)]==0){
					for(int k = )
					ans+=uvw[j].third;
					conect[make_pair(i,other)]=1;
				}
			}
		}
	}*/
	
	cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
	
}
