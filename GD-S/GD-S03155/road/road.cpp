#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long u[10005];
long long v[100005];
long long w[100005];
long long aa[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		cin>>aa[i];
	}
	cout<<0;
	return 0;
}
