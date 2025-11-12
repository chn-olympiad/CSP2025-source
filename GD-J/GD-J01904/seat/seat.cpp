#include <bits/stdc++.h>
using namespace std;
int a[2025];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,final;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) cin>>a[i];
	final=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n*m; i++)
		if(a[i]==final) {
			if(!(i%n))
				if((i/n)&1) cout<<i/n<<' '<<n;
				else cout<<i/n<<' '<<1;
			else 
				if((i/n)&1) cout<<i/n+1<<' '<<(n-i%n)+1;
				else  cout<<i/n+1<<' '<<i%n;
		}
	return 0;
}
//不要爆零
//Ayasa我来见你了 
