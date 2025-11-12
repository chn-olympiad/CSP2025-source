#include<bits/stdc++.h>
using namespace std;
int n,m,a[10086],s,v;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		s=a[1];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(s==a[i]){
			v=n*m-i+1;
		}
	}
	if(v%n!=0){
		if((v/n+1)%2==0){
			cout<<v/n+1<<" "<<n-v%n+1;
		}else{
			cout<<v/n+1<<" "<<v%n;
		}  
	}else{
		if(v/n%2==0){
			cout<<v/n<<" "<<1;
		}else{
			cout<<v/n<<" "<<n;
		}
	}
	return 0;
}
