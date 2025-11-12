#include <bits/stdc++.h>
using namespace std;
int n,z,d,a;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a>d){
			d=a;
		}
		z+=a;
	}
	if(z>2*d){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
