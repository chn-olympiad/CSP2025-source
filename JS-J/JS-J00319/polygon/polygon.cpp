#include<bits/stdc++.h>
using namespace std;



int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3){
		int a;
		while(n--) cin>>a;
		cout<<0<<endl;
		return 0;
	}
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b>c&&abs(a-b)<c) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
