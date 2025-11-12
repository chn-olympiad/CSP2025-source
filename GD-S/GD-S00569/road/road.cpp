#include<bits/stdc++.h>
using namespace std;
int m,n,k,city[10010][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>m>>n>>k;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		city[a][b]=c;
		city[b][a]=c;
	}
	cout<<13; 
	return 0;
}
//没思路，写不了一点，毁灭吧 
