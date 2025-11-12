#include <bits/stdc++.h>
using namespace std;
string a[200007],b[200007];
int n,q;
int main()
{
//	freopen("replace.in","r",stdin);
//	freopen("replayce.out","out",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1; i <= n; i++)
	{
		cin >>a[i] >> b[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cout<<a[i] <<"  "<< b[i] << endl;
	}
	return 0;
}
