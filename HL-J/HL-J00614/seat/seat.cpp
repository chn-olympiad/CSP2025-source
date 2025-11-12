#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num=1;
	cin>>n>>m;
	int a[10];
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[1]<a[i])
			num++;
	}
	if(num==1){
			cout<<1<<" "<<1;
	}
	else if(num==n*m){
		if(n%2==0)
			cout<<n<<" "<<1;
		else
			cout<<n<<" "<<m;
	}
	else if(num<=n){
		cout<<1<<" "<<num;
}
	else if(num>=n && num<2*n){
		if(n%2==0 && m%2==0){
		cout<<num/n+1<<" "<<abs((num-n)-(m+1));
	}
		else if(n%2==0 && m%2==1){
			cout<<num/n+1<<" "<<abs(-(num-n)+m);
		}
		else if(n%2==1 && m%2==0){
			cout<<num/n+1<<" "<<abs((n+1)-(num-n));
		}
		else{
			cout<<num/n+1<<" "<<abs((n+1)-(num-n));
		}
	}
	else{
		if((num/n+1)%2==1){
		if(m%2==0){
			cout<<num/n+1<<" "<<abs((n+1)-(num-(num/n)*n));
		}
		else{
			cout<<num/n+1<<" "<<abs(num-(num/n)*n);
		}
	}
	else{
		if(m%2==0){
			cout<<num/n+1<<" "<<abs((n+1)-(num-(num/n)*n));
		}
		else{
			cout<<num/n+1<<" "<<abs(num-(num/n)*n);
		}
	}
	}
	return 0;
}
