#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k,q=0,u,v,w,c,a[20000];
	string s1,s2;
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w;
		q+=w;
	}
	for(ll i=1;i<=k;i++){
		cin>>c;
		for(ll j=1;j<=m;j++){
			cin>>a[j];
		}
	}
	cout<<w;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
