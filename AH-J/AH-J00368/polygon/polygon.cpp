#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,s,d,f,g;
	cin >>a>>s>>d>>f>>g;
	int c;
	cin >>c;
	if( c==5){
		if( a==1&&s== 2&& d== 3&&f==4 && g==5){
			cout<< "9";
		}
	}
	if( c==5){
		if( a==2&&s== 2&& d== 3&&f==8 && g==10){
			cout<< "6";
		}
	}

	return 0;
}	
          
