#include <bits/stdc++.h>
using namespace std;
long long n,m,a[105],b,c,r;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m*2;i++){
		cin>>a[i];
		i++;
	}
	b=a[1];
	for(int i=1;i<=n*m;i++){
		if(a[i] ==b && i==1){
			c=1;
		}else if(a[i]<b){
			i++;
		}
	}
	for(int i=1;i<n*m;i++){
		if(a[i]==b){
	 cout<<i%n<<r/m+2;
		}
	}
	return 0;
}