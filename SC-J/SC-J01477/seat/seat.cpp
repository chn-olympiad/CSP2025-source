#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],x,y;
int main(){
	cin>>n>>m>>y;
	a[y]++;
	for(int i=1;i<n*m;i++){
		cin>>x;
		a[x]++;
	}
	x=0;
	for(int i=100;i>=y;i--){
		if(a[i]!=0){
			x+=a[i];
		}
	}
	if(x<=n){
		cout<<1<<" "<<x;
		return 0;
	}
	if(x%n==0){
		cout<<x/n<<" ";
		if((x/n)%2==1){
			cout<<n;
		}else{
			cout<<1;
		}
	}else{
		cout<<(x/n)+1<<" ";
		if((x/n)%2==1){
			cout<<x%n+1;
		}else{
			cout<<n-x%n-1;
		}
	}
	return 0;
}