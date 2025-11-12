#include <bits/stdc++.h>
using namespace std;
int n, m, a[200], ans, me;
bool cmp(int x, int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	me=a[1];
	sort(a+1, a+1+n*m, cmp);
	for(int i=1; i<=n*m; i++){
		if(a[i]==me) ans=i;
	}
	cout<<(ans+n-1)/n<<" ";
	if(((ans+n-1)/n)%2)
		cout<<ans-((ans+n-1)/n-1)*n<<"\n";
	else cout<<n+1-(ans-((ans+n-1)/n-1)*n)<<"\n";
	return 0;
}
