#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101];
	int ip;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ip=a[1];
	for(int i=1;i<=n*m-1;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	int i;
	for(i=1;i<=n*m;i++){
		if(a[i]==ip)break;
	}
	if(i%n==0){
		cout<<i/n<<' ';
		if((i/n)%2==0){
			cout<<'1';
		}else{
			cout<<n;
		}
	}else{
		cout<<i/n+1<<' ';
		if((i/n+1)%2==0){
			cout<<n-i%n+1;
		}else{
			cout<<i%n;
		}
	}
	return 0;
}
