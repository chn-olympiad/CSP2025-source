#include<bits/stdc++.h>
using namespace std;
int q,w,n,m,a[105];
int b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			w=a[i];
		}
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==w){
			q=n*m-i+1;
		}
	}
	if(q%n==0){
		if(q/n%2==1){
			cout<<q/n<<" "<<n;
		}
		if(q/n%2==0){
			cout<<q/n<<" "<<1;
		}
	}
	if(q%n!=0){
		if((q/n+1)%2==1){
			cout<<q/n+1<<" "<<q%n;
		}
		if((q/n+1)%2==0){
			cout<<q/n+1<<" "<<n-(q%n)+1;
		}
	}
	return 0;
}
