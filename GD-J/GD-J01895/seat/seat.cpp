#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,l=1;
	cin>>n>>m;
	long long num=n*m;
	int a1,a2;
	cin>>a1;
	for(int i=1;i<=num;i++){
		cin>>a2;
		if(a2>a1){
			l++;
		}
	}
	long long a,b,c;
	a=l/n;
	b=l%n;
	if(b!=0){
		a++;
	}
	if(a%2==1){
		if(b!=0){
			c=b;
		}else{
			c=n;
		}
	}else{
		if(b!=0){
			c=n-b+1;
		}else{
			c=1;
		}
	}
	cout<<a<<" "<<c;
	return 0;
}
