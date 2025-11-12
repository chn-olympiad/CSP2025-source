#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3) cout<<0;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(2*max(a,max(b,c))>(a+b+c)) cout<<0;
		else
		cout<<1;
	}
	return 0;
}
