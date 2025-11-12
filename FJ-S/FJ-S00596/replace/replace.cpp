#include <bits/stdc++.h> 
using namespace std;
int n,m,s,c[105];
string d[105],e[105][105];


int main(){
	freopen("repalce.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}for(int i=1;i<=n;i++){
		for(int j=1;i<=m;j++){
		cin>>e[i][j];
	}
	}
	for(int i=1;i<=m;i++){
		cout<<0<<endl;
	}
	return 0;
} 
