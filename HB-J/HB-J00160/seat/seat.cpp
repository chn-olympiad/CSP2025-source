#include<bits/stdc++.h>
using namespace std;
int n,m,x,a,sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<=n*m-1;i++){
		cin>>a;
		if(a>x){
			sum++;
		}
	}
	if(sum==0){
		cout<<"1 1";
		return 0;
	}
	if((sum/n)%2==0){
		if(sum%n){
			cout<<sum/n+1<<" "<<sum%n+1;
		}else{
			cout<<sum/n+1<<" 1";
		}
	}else{
		if(sum%n){
			cout<<sum/n+1<<" "<<n-sum%n;
		}else{
			cout<<sum/n+1<<" "<<n;
		}
	}
	return 0;
}
