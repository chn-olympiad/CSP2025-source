#include<bits/stdc++.h>
using namespace std;
int m[1234588];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,n,sum=1;
	cin>>a>>b>>n;
	if(a==1&&b==1){
		cout<<"1 1";
		return 0;
	}
	for(int i=1;i<a*b;i++){
		cin>>m[i];
		if(m[i]>n){
			sum++;
		}
	}
	int o;
	if(sum%a!=0){
		o=sum/a+1;
	}
	else{
		o=sum/a;
	}
	cout<<o;
	cout<<" ";
	int p=sum%a;
	if(o%2==0){
		if(p==0){
			cout<<1;
		}
		else{
			cout<<a+1-p;
		}
	}
	else{
		if(p==0){
			cout<<a;
		}
		else{
			cout<<p;
		}
	}
	
	return 0;
	}
	
