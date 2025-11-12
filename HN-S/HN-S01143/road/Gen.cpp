#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,W=1e9;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	//freopen(".in","r",stdin);
	freopen("1.in","w",stdout);
	int n=1e4,m=1e6,k=10;
	cout<<n<<' '<<m<<' '<<k<<'\n';
	for(int i=2;i<=n;i++){
		cout<<i<<' '<<rand()%(i-1)+1<<' '<<rand()%W<<'\n';		
		m--;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cout<<rand()%n+1<<' '<<rand()%n+1<<' '<<rand()%W<<'\n';
			m--;
			if(m==0) break;
		}
		if(m==0) break;
	}
	for(int i=1;i<=k;i++){
		cout<<rand()%W<<' ';
		for(int i=1;i<=n;i++)
			cout<<rand()%W<<' ';
		cout<<'\n';
	}
	
	return 0;
}

