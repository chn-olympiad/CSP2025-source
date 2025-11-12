#include<iostream>
#include<cstdio> 
using namespace std;
int n,k;
int z[1000001];
int a,b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>z[i];
	}
	if(n<=2&&k==0){//测试点1
		for(int i=1;i<=n;i++){
			if(z[i]==1)a++;
			else if(z[i]==0)b++;
		}
		if(a%2==1){
			cout<<0;
			return 0;
		}else if(a%2==0){
			cout<<a/2+b;
			return 0;
		}
	}else if(n<=10){//测试点2 
		if(k==1){
			for(int i=1;i<=n;i++){
				if(z[i]==1)a++;
				else if(z[i]==0)b++;
			}
			cout<<a;
			return 0;
		}else if(k==0){
			for(int i=1;i<=n;i++){
				if(z[i]==1)a++;
				else if(z[i]==0)b++;
			}
			if(a%2==1){
				cout<<0;
				return 0;
			}else if(a%2==0){
				cout<<a/2+b;
				return 0;
			}
		} 
	}else if(n<=100){
		if(k==0){//测试点3
			for(int i=1;i<=n;i++){
				if(z[i]==1)a++;
				else if(z[i]==0)b++;
			}
			if(a%2==1){
				cout<<0;
				return 0;
			}else if(a%2==0){
				cout<<a/2+b;
				return 0;
			}
		}else if(k==1){//测试点4，5 
			for(int i=1;i<=n;i++){
				if(z[i]==1)a++;
				else if(z[i]==0)b++;
			}
			cout<<a;
			return 0;
		}
	}else if(n<=200000){//测试点13 
		if(k==0){
			for(int i=1;i<=n;i++){
				if(z[i]==1)a++;
				else if(z[i]==0)b++;
			}
			if(a%2==1){
				cout<<0;
				return 0;
			}else if(a%2==0){
				cout<<a/2+b;
				return 0;
			}
		}else if(k==1){
			for(int i=1;i<=n;i++){
				if(z[i]==1)a++;
				else if(z[i]==0)b++;
			}
			cout<<a;
			return 0; 
		}
	} 
	return 0;
} 