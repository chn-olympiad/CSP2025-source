#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long a, c=0, b=0;
	cin >> a;
	c = a/10;
	b = a%10;
	if (b<=c) 
	{
		cout << a;
	}
	else
	{
		cout << b*10+c;
	}

	return 0;
}
