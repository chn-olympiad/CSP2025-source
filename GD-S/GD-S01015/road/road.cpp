#include<bits/stdc++.h>
using namespace std;
int n,m,k,s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		s+=c; 
	} 
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			int x;
			cin>>x;
		}
	}
	cout<<s;
}
