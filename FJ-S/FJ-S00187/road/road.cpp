#include <bits/stdc++.h>
using namespace std;
vector <int> w;
int c,a;
int n,m,k,u,v,total=0;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w[i];
	}
	for(int i=0;i<=k;i++){
		cin>>c;
		cin>>a;
	}
	sort(w.begin(),w.end());
	for(int i=0;i<n-1;i++){
		total+=w[i];
	}
	cout<<total;
	return 0;
} 
