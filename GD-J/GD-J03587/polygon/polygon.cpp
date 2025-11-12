#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long a,b,c,d;
	cin>>a;
	cin>>b>>c>>d;
	if(b+c+d>b*2&&b+c+d>d*2&&b+c+d>c*2)
	cout<<"1";
	else
	cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
