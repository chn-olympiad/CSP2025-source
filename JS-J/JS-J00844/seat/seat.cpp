# include <bits/stdc++.h>
# define int long long
using namespace std;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[200];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int xm=a[1],pm;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==xm) pm=i;
	}
	int zbl=(pm%n==0?pm/n:pm/n+1);
	int zbh=(pm%n==0?((pm/n)%2==0?1:m):((pm/n)%2==0?pm%n:n+1-(pm%n)));
	cout<<zbl<<" "<<zbh;
	return 0;
}
