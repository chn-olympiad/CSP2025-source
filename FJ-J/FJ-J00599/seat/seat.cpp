#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1005];

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;++i){
		if(a[i]==t){
			t=i;
			break;
		}
	}
	int r=(t+n-1)/n;
	int c=t%(2*n);
	if(c>n) c=2*n-c+1;
	cout<<r<<" "<<c;
	return 0;
}
