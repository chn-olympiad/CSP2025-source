#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int peo=n*m;
	int pf[peo+5],xm;
	for(int i=0;i<peo;i++){
		cin>>pf[i];
	}
	xm=pf[0];
	sort(pf,pf+peo);
	reverse(pf,pf+peo);
	for(int i=0;i<peo;i++){
		if(pf[i]==xm){
			cout<<(i/n)+1<<' ';
			if(((i/n)+1)%2) cout<<(i%m)+1;
			else cout<<m-((i%m));
			return 0; 
		}
	}
	return 0;
}
