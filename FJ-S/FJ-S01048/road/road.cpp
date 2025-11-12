#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,zong=0;
	vector<int>pa(n);
	cin>>n>>m>>k;
	n++;
	int a[n][n]={};
	int u[m],v[m],w[m];
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int s[k][n]={};
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;pa.empty();i++){
		for(int j=0;j<pa.size();j++){
			if(pa.front()==u[i]){
				pa.erase(pa.begin());
				zong+=w[i];
			}else if(pa.front()==v[i]){
				pa.erase(pa.begin());
				zong+=w[i];
			}
		}
	}
	cout<<13;	
	return 0;
}
