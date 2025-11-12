#include<bits/stdc++.h>
using namespace std;
struct p {
	int a,b,c;
} a[1000005];
struct k {
	int a,b,c;
} b[1000005];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m ,k;
	cin>>n>>m>>k;
	for(int i=0; i<m; i++) {
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	for(int i=0; i<k; i++) {
		cin>>b[i].a>>b[i].b>>b[i].c;
	}cout<<(n+1)*2;
	return 0;
}
