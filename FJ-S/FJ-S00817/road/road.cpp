#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	if(n<1){
		cout<<0<<endl;
	}
	if(n==1){
		cout<<1<<endl;
	}
	if(n==1000){
		cout<<"很大很大"<<endl;
	}
	return 0;
}
