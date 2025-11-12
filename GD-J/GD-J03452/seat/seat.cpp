#include<bits/stdc++.h>
using namespace std;
const int N=103;
int n,m,a[N],t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			int j=(i-1)/n+1;
			cout<<j<<' ';
			if(j%2)cout<<i-n*(j-1);
			else cout<<n*j-i+1;
		}
	}
}
