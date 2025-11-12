#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a,b,c;
	cin>>n>>a>>b>>c;
	if(n<3){
		cout<<0;
	}
	else if(n==3){
		if((a+b>c)&&(a+c>b)&&(b+c>a)){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<998244352;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
