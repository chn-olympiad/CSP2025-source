#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[100000],cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])cnt++;
	}
	cout<<((cnt+n-1)/n)<<" ";
	if(((cnt+n-1)/n)%2==1){
		if(cnt%n==0)cout<<n;
		else cout<<cnt%n;
	}
	else{
		if(cnt%n==0)cout<<1;
		else cout<<n-cnt%n;
	}
	return 0;
} 