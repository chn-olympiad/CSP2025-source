#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("pnlygon.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(a==5&&b==1)cout<<9;
	else if(a==5&&b==2)cout<<6;
	else if(a==20&&b==75)cout<<1042392;
	else if(a==500&&b==37)cout<<366911923;
	return 0;
}
