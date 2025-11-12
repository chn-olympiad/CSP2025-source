#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int mod=1e9+1;
int main(){
	freopen("road.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n=10000,m=1000000,k=10;
	cout<<n<<' '<<m<<' '<<k<<'\n';
	mt19937 random(time(0));
	for(int i=2;i<=n;i++){
		cout<<random()%(i-1)+1<<' '<<i<<' '<<random()%mod<<'\n';
	}
	for(int i=n;i<=m;i++){
		int u=random()%n+1,v=random()%(n-1)+1;
		if(v>=u) v++;
		cout<<u<<' '<<v<<' '<<random()%mod<<'\n';
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++) cout<<random()%mod<<' ';
		cout<<'\n';
	}
	return 0;
}