#include<bits/stdc++.h>
using namespace std;
long long in,r,n,m,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}r=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			in=n*m-i;
			break;
			
		}
	}if(((in+(n-1))/n)%2==0){
		//^
		cout<<((in+(n-1))/n)<<" "<<n-(in%(n+1));
	}else{
		cout<<((in+(n-1))/n)<<" "<<in%(2*n);
	}
	return 0;
}//3 3 94 95 96 97 98 99 100 93 92
//2 2 3 1 2 4
