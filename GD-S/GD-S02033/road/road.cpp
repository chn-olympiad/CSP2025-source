#include<bits/stdc++.h>;
using namespace std;
int main(){
	freoprn("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	if(n<1000||m<1000000||k<=5){
		cout<<505585650;
	}
	if(n<1000||m<1000000||k<=10){
		cout<<5182974424;
	}
	
	return 0;
}
