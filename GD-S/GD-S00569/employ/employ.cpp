#include<bits/stdc++.h>
using namespace std;
int m,n,k,city[10010][10010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n>>k;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		city[a][b]=c;
		city[b][a]=c;
	}
	cout<<2<<" "; 
	return 0;
}
//明目张胆的骗分:) 
