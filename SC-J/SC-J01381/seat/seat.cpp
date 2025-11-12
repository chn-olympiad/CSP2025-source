#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,g[200];
int xm,o,ansn,ansm;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>g[i];
	}
	xm=g[1];
	int jjj=n*m;
	sort(g+1,g+jjj+1);
	for(int i=1; i<=n*m; i++){
		if(g[i]==xm){
			o=n*m+1-i;
			break;
		}
	}
//	cout<<o<<'\n';
	ansn=(o+m-1)/m;
	if(ansn%2==1){
		ansm=(o-(ansn-1)*m);
	}
	else{
		ansm=(ansn*m-o)+1;
	}
	cout<<ansn<<' '<<ansm;
	return 0;
}