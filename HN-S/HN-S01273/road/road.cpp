#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w;
	bool friend operator<(node i,node j){
		if(i.w==j.w)return i.u<j.u;
		return i.w<j.w;
	}
};
set<node>s;
int c[15],a[15][20010];

signed main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		s.insert((node){x,y,z});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	int minn=1e18;
	for(int i=0;i<(1<<k);i++){
		int sum=0;
		for(int j=0;j<k;j++){
			if((1<<j)&i){
				sum+=c[j+1];
				for(int A=1;A<=n;A++){
					s.insert((node){j+n+1,A,a[j+1][A]});
				}
			}
		}
		for(auto pp:s){
			int fx=find(pp.u),fy=find(pp.v);
			
		}
		
	}
	return 0;
}
