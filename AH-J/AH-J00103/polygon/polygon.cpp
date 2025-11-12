#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a1,a2,a3;
	cin>>n;
	cin>>a1>>a2>>a3;
	if(max(a1,max(a2,a3))*2>=a1+a2+a3){
		cout<<0;
	}
	else{
		cout<<1;
	}
	return 0;
}
