#include <iostream>
#include <fstream>
using namespace std;
int a[50005],n,k,s;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor","r",stdin);
	freopen("xor","w",stdin);
	cin>>n>>k;
	for(int i=0; i<n; i++)cin>>a[i];
	for(int i=0; i<n; i++)
		if(a[i]==k)a[i]=0,s++;
	cout<<s;
	return 0;
}
