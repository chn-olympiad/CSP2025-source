#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n*m]={0};
	cin>>a[0];
	long long x=1;
	for(long long i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			x++;
		}
	}
	long long nn,mm;
	mm=(x/m)+1;
	if(mm%2==0&&x%n!=0){
		nn=n-(x%n)+1;
	}
	else if(mm%2==1&&x%n!=0){
		nn=x%n;
	}
	else if(mm%2==0&&x%n==0){
		mm--;
		nn=n;
	}
	else if(mm%2==1&&x%n==0){
		mm--;
		nn=1;
	}
	cout<<mm<<" "<<nn;
	return 0;
}
