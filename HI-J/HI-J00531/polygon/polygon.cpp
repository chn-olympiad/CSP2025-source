#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		long long a,b,c;
		cin>>a>>b>>c;
		if(a+b>c&&a+c>b&&b+c>a) cout<<1;
		else cout<<0;
	} 
	else cout<<0;
	return 0;//¼ÓÓÍ£¡£¡£¡£¡£¡£¡£¡
}

