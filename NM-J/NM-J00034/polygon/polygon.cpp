#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,h=0;
	cin>>n;
	for(int i=n;i>=1;i--) h+=i;
	cout<<h;
	return 0;
}
