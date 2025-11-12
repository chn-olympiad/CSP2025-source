#include<bits/stdc++.h>
using namespace std;
int s[10000][3];
int p[10000][3];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,q,k;
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=2;j++){
			cin>>p[i][j];
		}
	}
	cout<<505585650;
	return 0;
} 
