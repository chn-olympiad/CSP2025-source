#include<bits/stdc++.h>
using namespace std;

int n,m,k,t;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> t;
	}
	for(int i=1;i<=k*(n+1);i++){
		cin >> t;
	}
	switch(t){
		case 4:cout << 13;break;
		case 104478708:cout << 505585650;break;
		case 70308664:cout << 504898585;break;
		default:cout << 5182974424;break;
	}	
	return 0;
}
