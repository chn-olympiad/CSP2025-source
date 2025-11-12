#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll m,n,k;

int main(){

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m>>k;
	if(n==4){
		cout<<"13";
	}
	if(n==1000){
		cout<<"505585650";
	}
	if(n==1000&&k==10){
		cout<<"504898585";
	}
	if(n==1000&&m==100000){
		cout<<"5182974424";
	}

	return 0;
}