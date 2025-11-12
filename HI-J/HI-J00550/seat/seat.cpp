#include<bits/stdc++.h>
using namespace std;
long long n , m , a[10001]={};
long long r , id=1 , s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	r=a[1];
	for(int i=2 ; i<=n*m ; i++){
		cin >> a[i];
		break;
	}
	sort(a , a+n*m+1);
	for(int i=n*m ; i>=1 ; i--){
		if(a[i]==r){
			id=(m*n-i+1);
		}
	}
	if(id%n==0){
		s=id/n;
		cout << s << ' ';
	}
	else if(id%n!=0){
		s=id/n+1;
		cout << s << ' ';
	}
	id=id-(s-1)*n;
	if(s%2){
		cout << id;
	}
	else{
		cout << (n-id+1);
	}
	return 0;
} 
