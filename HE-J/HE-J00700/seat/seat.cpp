#include<bits/stdc++.h>
using namespace std;
int const N = 110;
int n,m;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	int xm = a[1];
	sort(a+1,a+n*m+1);
	
	for(int i = 1,j = n*m;j>=1;i++,j--){
		if(a[j] == xm){
			if((i/n+1)%2&&i%n){
				cout<<i/n+1<<" "<<i%n;
			}else if((i/n)%2&&i%n==0){
				cout<<i/n<<" "<<n;
			}else if((i/n)%2==0&&i%n==0){
				cout<<i/n<<" "<<1;
			}else if((i/n+1)%2==0&&i%n){
				cout<<i/n+1<<" "<<n-(i%n)+1;
			}
		}
	}
	return 0;
}
