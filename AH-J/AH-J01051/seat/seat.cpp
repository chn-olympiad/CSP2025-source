#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1010],R,l;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a,a+n);
	if(R/n==0){
		cout<<R/n<<" ";
		l=R/n;
	}else{
		cout<<R/n+1<<" ";
		l=R/n+1;
	}
	if(l/2==0){
		cout<<R%n;
	}else{
		cout<<n-R%n+1;
	}
	return 0;
}
