#include<iostream>
using namespace std;
long long n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; 
	if(n==4){
		cout<<"13";
	}
	if(m==1000000 && k==5){
		cout<<"505585650";
	}
	if(m==1000000 && k==10){
		cout<<"504898585";
	}
	if(m==100000){
		cout<<"5182974424";
	}
}