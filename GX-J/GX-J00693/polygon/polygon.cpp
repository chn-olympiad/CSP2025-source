#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int a,b,c;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>a>>b>>c;
	int maxn=max(max(a,b),c);
	if(a+b+c>maxn*2)cout<<1;
	else cout<<0;

	return 0;
}
