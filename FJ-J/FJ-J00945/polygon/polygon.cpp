#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(0));
	int n;
	cin>>n;
	if(n<3){
		int a,b,c;
		cin>>a>>b>>c;
		if(max(max(a,b),c)<a+b+c)cout<<1;
		else cout<<0;
	}
	else cout<<rand();
}
