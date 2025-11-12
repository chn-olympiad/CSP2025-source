#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int l=n,ans=0;
	for(int i=1;i<=m;i++){
		cin>>n>>n>>n;
		ans+=n;
	}
	for(int i=1;i<=k;i++){
		cin>>n;
		for(int j=1;j<=l;j++) {
			cin>>n;
			ans+=n; 
		}
	}
	cout<<ans*m/k;
}
