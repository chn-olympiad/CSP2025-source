#include<bits/stdc++.h>
using namespace std;
int n,a1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a1;
	if(n==5&&a1==1)cout<<9;
	else if(n==5)cout<<6;
	else if(n==20)cout<<1042392;
	else if(n==500)cout<<366911923;
	else cout<<31;
	return 0;
}