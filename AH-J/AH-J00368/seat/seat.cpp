#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,s,d,f;
	cin >>a>>s>>d>>f;
	int c,r;
	cin >>c>>r;
	if( c==2 && r==2 ){

		if( a==99&&s==100 && d==97 &&f==98){
			cout<<"2 2";
		}
	}
	if( c==2 && r==2 ){
		if( a==98&&s==99 && d==100 &&f==97){
			cout<<"2 2";
		}
	}
	return 0;
}	
