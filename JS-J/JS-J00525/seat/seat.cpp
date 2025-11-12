#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;++i){
		cin >> a[i];
	}int k=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			//~ cout << "Debug:" << i << '\n';
			cout << ceil(1.0*i/n);
			if(int(ceil(1.0*i/n))%2==0)
				cout << ' '<<(i%n==0?1:m-i%n+1);
			else cout<<' '<<(i%n==0?m:i%n);
			return 0;
		}
	}
	return 0;
}
