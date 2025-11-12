#include<bits/stdc++.h>
using namespace std;
char b[1000101];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int d=0;
	cin>>a;
	for(int c=0;c<a.size();c++) if(a[c]>='0'&&a[c]<='9') b[d++]=a[c];
	sort(b,b+d);
	for(int c=d-1;c>=0;c--) cout<<b[c];
	return 0;
}
