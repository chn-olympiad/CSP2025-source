#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,c,r;
	long long a[10086];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		if(m<=1){
			a[i]=i=m*n-i+1;
			c=n;
			r=m;
			cout<<c<<r;
		}	
	}
	return 0;
} 