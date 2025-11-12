#include<bits/stdc++.h> 
using namespace std;
long long c,r,a,sum,a1=0;
long long b,b2,n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	sum = n*m;
	cin >> a1;
	for(int i=2;i<=sum;i++){
		cin >> a;
		if(a>a1){
			b++;
		}
	}
	b=b+1;
	if(b%m!=0){
		c = b/m+1;
	}else{
		c = b/m;
	}
	if((b/n+1)%2!=0){
		if(b%n==0){
			r = n;
		}else{
			r = b%n;
		}
	}else{
		if(b%n==0){
		   r = 1;
		}else{
			b2 = n-b%n;
			for(int j=n;j>=b2;j--){
				r = 0;
				r = j;
			}
		}
	}
	cout << c << " "<< r+1;
	return 0;
}
