#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w;
	vector<int>sa;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		sa.push_back(w);
	}
	int muc=0;
	sort(sa.begin(),sa.end());
	for(int i=0;i<n-1;i++){
		muc+=sa[i];
	}
	cout<<muc;
	return 0;
}
