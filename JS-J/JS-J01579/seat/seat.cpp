#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int mine=a[1];
	int pos;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(mine==a[i]){
			pos=n*m-i+1;
		}
	}
	cout<<(pos+n-1)/n<<' ';
	if((pos+n-1)/n%2==1){
		if(pos%n==0) cout<<n;
		else cout<<pos%n;
	}else cout<<n-pos%n+1;
	return 0;
}

