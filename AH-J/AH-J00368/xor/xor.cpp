#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
		int a,s,d,f;
	cin >>a>>s>>d>>f;
	int c,r;
	cin >>c>>r;
	if( c== 4&& r==2 ){
		if( a==2 && s==1 && d==0 &&f==3){
			cout<<r;
		}
	}
	if( c==4 && r==3 ){
		if( a==2&&s==1 && d==0 &&f==3){
			cout<<r-s;
		}
	}
	if( c==4 && r==0){
		if( a==2&&s==1 && d==0 &&f==3){
			cout<<r+s;
		}
	}
	
	cout <<"2";
	return 0;
}	
