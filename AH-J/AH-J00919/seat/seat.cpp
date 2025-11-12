#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int aa=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==aa){
			aa=n*m-i+1;
		}
	}
	if(aa/n%2==0){
		if(aa%n==0)cout<<aa/n<<" "<<1;
		else cout<<aa/n+1<<" "<<aa%n;
	}
	else {
		if(aa%n==0)cout<<aa/n<<" "<<n;
		else cout<<aa/n+1<<" "<<n-aa%n+1;
	}
	return 0;
}
