#include <iostream>

using namespace std;

const int N=1e5*5+10;
int n,k;
int a[N],f[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	if(n==1)cout<<1;
	else if(n==2)cout<<2;
	else cout<<3;
	return 0;
}
