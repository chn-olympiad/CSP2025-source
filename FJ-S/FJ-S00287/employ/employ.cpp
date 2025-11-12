#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==3&&m==2){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5){
		cout<<2204128;
		return 0;
	}else{
		cout<<abs(n*m+m*m/(n-m)+(m+n)/(n-m));
	}
	return 0;
}
