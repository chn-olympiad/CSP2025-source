#include<bits/stdc++.h>
using namespace std;
struct M {
	int v,u,w;
} a1[1000010];
struct K {
	int c;
	vector<int> a;
} a2[1000010];
int main() {
	freopen("road.in.txt","r",stdin);
	freopen("road.out.txt","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0; i<m; i++) {
		cin>>a1[i].v>>a1[i].u>>a1[i].w;
	}
	bool isorno=0;
	for(int i=0; i<k; i++) {
		cin>>a2[i].c;
		if(a2[i].c) {
			isorno=1;
		}
		for(int j=0; j<m; j++) {
			cin>>a2[i].a[i];
		}
	}
	if(!isorno) {
		cout<<0<<'\n';
	}
}
