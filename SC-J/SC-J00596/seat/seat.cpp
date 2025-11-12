#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	int R=a[1],c=0,r=0;
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1; i<=n*m; i++){
		if(a[i]==R){
			c=ceil(i*1.0/n);
			r=i%n;
			if(c%2==0){
				r=n-r+1;
			}
			if(r==0){
				r=n;
			}
			break;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}