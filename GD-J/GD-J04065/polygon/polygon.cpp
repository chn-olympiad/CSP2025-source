#include<bits/stdc++.h>
using namespace std;
int n;
int a,b,c;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a>>b>>c;
	if(a+b+c>max(a,max(b,c))*2) {
		cout<<1;
	} else {
		cout<<0;
	}
	return 0;
}
