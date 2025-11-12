#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[101];
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	if(n==1&&m==1) cout<<n<<" "<<m;
	else if(n==1&&m==2){
		if(a[1]>a[2]) cout<<1<<" "<<1;
		else cout<<2<<" "<<1;
	}
	else if(n==1&&m==3){
		if(a[1]>a[2]&&a[1]>a[3]) cout<<1<<" "<<1;
		else if(a[1]<a[2]&&a[1]>a[3]) cout<<2<<" "<<1;
		else cout<<3<<" "<<1;
	}
	else if(n==1&&m==4){
		if(a[1]>a[2]&&a[1]>a[3]&&a[1]>a[4]) cout<<1<<" "<<1;
		else if(a[1]<a[2]&&a[1]>a[3]&&a[1]>a[4]) cout<<2<<" "<<1;
		else if(a[1]>a[2]&&a[1]<a[3]&&a[1]<a[4]) cout<<3<<" "<<1;
		else cout<<4<<" "<<1;
	}
	else if(n==2&&m==1){
		if(a[1]>a[2]) cout<<1<<" "<<1;
		else cout<<1<<" "<<2;
	}
	else if(n==2&&m==2){
		if(a[1]>a[2]&&a[1]>a[3]&&a[1]>a[4]){
			cout<<1<<' '<<1;
		}else if(a[1]<a[2]&&a[1]>a[3]&&a[1]>a[4]){
			cout<<1<<' '<<2;
		}else if(a[1]>a[2]&&a[1]<a[3]&&a[1]>a[4]){
			cout<<2<<' '<<2;
		}else if(a[1]<a[2]&&a[1]<a[3]&&a[1]<a[4]){
			cout<<2<<' '<<1;
		}
	}
}
