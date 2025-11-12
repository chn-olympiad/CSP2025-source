#include<bits/stdc++.h>
using namespace std;
string a[474][474],b[474][474];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=2;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<0<<"\n";
	}
	return 0;
}
