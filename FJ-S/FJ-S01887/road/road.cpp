#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m,k,b[N];
//struct node{
//	bool torf;
//	int w;
//	int r;
//};
struct vl{
	int a[N];
	int c;
};
vl tr[N];
vector<int> mp[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v>>b[i];
		mp[u].push_back(v);
		mp[u].push_back(b[i]);
	}
	for(int i=1;i<=k;i++){
		cin>>tr[i].c;
		for(int j=1;j<=n;j++){
			cin>>tr[i].a[j];
		}
	}
	cout<<n*m+k;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
