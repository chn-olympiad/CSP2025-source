#include <bits/stdc++.h>
using namespace std;
int a,b,n,k; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	cin>>a>>b;
	if(a^b==k||a^a==k||b^b==k) 
	cout<<1;
	else
	cout<<0;
	return 0;
 } 
