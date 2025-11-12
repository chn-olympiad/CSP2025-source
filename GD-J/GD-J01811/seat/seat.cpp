#include<bits/stdc++.h>
using namespace std;
long long n,m,seat,num,ansx,ansy;
long long a[10005];
long long cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	seat=a[1];
	stable_sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==seat){
			num=i;
		}
	}
	ansx=num/n;
	if(ansx*n!=num){
		ansx++;
	}
	if(ansx%2){
		if(num%n==0){
			ansy=n;
		}else{
			ansy=num%n;
		}
	}else{
		if(num%n==0){
			ansy=1;
		}else{
			ansy=n-num%n+1;
		}
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}

