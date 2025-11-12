#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==t){
			int p=n*m-i+1;
			if(p%(2*n)==0){
				cout<<p/n<<" "<<1;
			}else if(p%(2*n)==n){
				cout<<p/n<<" "<<m;
			}else if(p%(2*n)<n){
				cout<<p/n+1<<" "<<p%n;
			}else{
				cout<<p/n+1<<" "<<n-(p%n)+1;
			}
		}
	}
	return 0;
}// 2 2 96 97 98 99
//2 2 98 100 97 99


