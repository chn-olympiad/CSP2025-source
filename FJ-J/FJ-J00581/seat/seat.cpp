#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],f,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	f=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			s=n*m-i+1;
			break;
		}
	}
	cout<<(s+n-1)/n<<' ';
	if(((s+n-1)/n)%2) cout<<(s%n==0?n:s%n);
	else cout<<n-(s%n==0?n:s%n)+1;
	return 0;
}
