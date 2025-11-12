#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n*m;i++){
		cin>>a[i];
	}
	long long k=n*m,x=a[0],y;
	sort(a+0,a+k+0,cmp);
	for(long long i=0;i<k;i++){
		if(a[i]==x){
			y=i+1;
			break;
	    }
	}
	int num;
	if(y%n==0){
		num=y/n;
	}
	else{
		num=y/n+1;
	}
	if(num%2==1){
	    if(y%n==0){
		    cout<<num<<" "<<n;
	    }
      	else if(y%n!=0){
		    cout<<num<<" "<<y%n;
	    }
	}
	else if(num%2==0){
		if(y%n==0){
		    cout<<num<<" "<<n;
	    }
	    else if(y%n!=0){
	  	    cout<<num<<" "<<n-y%n+1;
	    }
	}
	return 0;
}
