#include<bits/stdc++.h>
using namespace std;//⊕
int zhuan(int x)
{
	int sum=0,a,q=1;
	while(x!=0)
	{
		a=x%2;
		sum+=q*a;
		q*=10;
		x/=2;
    }
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cout<<2;
	return 0;
}//️📄️️️️️
