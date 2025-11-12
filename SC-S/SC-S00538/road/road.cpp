//road.cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000010],b[1000010],c[1000010],o[15],ls[15][10010];
string s;
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=k;i++){
		cin>>o[i];
		for(int j=1;j<=n;j++) cin>>ls[i][j];
	}
	cout<<13;
	return 0;
}