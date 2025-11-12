#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b>c&&a+c>b&&b+c>a)
	{
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
