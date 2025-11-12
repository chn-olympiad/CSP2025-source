#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1007];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+n*m+1);
	int zhiz,b1,temp;
	for(int i=n*m;i>=1;i--){
		if(a[i]==b){
			zhiz=n*m-i+1;
		}
	}
	b1=zhiz/n;
	if(zhiz%n==0){
		if(b1%2==0){
			cout<<b1<<" "<<1;
		}else{
			cout<<b1<<" "<<n;
		}
	}else{
		temp=zhiz%n;
		if((b1+1)%2==0){
			cout<<b1+1<<" "<<n-temp+1;
		}else{
			cout<<b1+1<<" "<<temp;
		}
	}
	return 0;
}
