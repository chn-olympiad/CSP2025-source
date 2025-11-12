#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			k=n*m-i+1;
			break;
		}
	}
	if(k%n==0){
		if((k/n)%2) cout<<k/n<<' '<<n;
		else cout<<k/n<<" 1";
	}
	else {
		if((k/n)%2) cout<<k/n+1<<' '<<n-(k%n)+1;
		else cout<<k/n+1<<' '<<k%n;
	}
	return 0;
}

