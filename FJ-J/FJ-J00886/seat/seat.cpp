#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b[105],c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		if(i==1){
			cin>>a;
		}else{
			cin>>b[i-1];
		}
	}
	sort(b+1,b+n*m,greater<int>());
	for(int i=1;i<n*m;i++){
		if(a>b[i]){
			c=i;
			break;
		}
	}
	cout<<(c+n-1)/n<<" ";
	if((c+n-1)/n%2==1){
		if(c%n==0){
			cout<<n;
		}else{
			cout<<c%n;
		}
	}else{
		if(c%n==0){
			cout<<"1";
		}else{
			cout<<n-c%n+1;
		}
	}
	return 0;
}
