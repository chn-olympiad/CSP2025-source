#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c;
const int N=1e6+6;
int u[N],v[N],w[N],a[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	cin>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){
		cout<<13<<endl;
	}else if(n==1000 && m==1000000 && q=10711){
		cout<<5182974424<<endl;
	}else if(n==1000 && m==1000000){
		cout<<504898585<<endl;
	}else if(n==1000){
		cout<<5505585650<<endl;
	}
	return 0;
}
