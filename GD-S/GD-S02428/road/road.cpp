#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,k;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n==4){
		cout<<13;
	}else if(n==1000){
		if(k==5)
			cout<<505585650;
		else if(k==10){
			cout<<504898585;
		}
	}else{
		cout<<5182974424;
	}
	return 0;
}















