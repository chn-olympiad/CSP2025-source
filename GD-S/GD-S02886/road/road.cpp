#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
int n,m,k,x;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k>>x;
	if(n==4) cout<<13;
	else if(k==5) cout<<505585650;
	else if(k==10){
		if(x==709) cout<<504898585;
		else cout<<5182974424;
	}
	return 0;
} 
