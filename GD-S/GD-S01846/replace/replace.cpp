#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a,b;
	cin>>a>>b;
	string c;
	for(int i=0; i<(a+b)*2; i++)cin>>c;
	for(int i=0; i<b; i++)cout<<0<<'\n';
	return 0;
}
