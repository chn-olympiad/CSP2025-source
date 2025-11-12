#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;

int main()
{	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int a;
	cin>>a;
	if(a<10)
	cout<<a;
	else if(a%10>a/10)
	cout<<a%10<<a/10;
	else
	cout<<a;
}
