#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a;
int n,k,f,t,s,b[1000500];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	for(int i=0; i<a.size(); i++)
		if(a[i]>='0'&&a[i]<='9')
			b[++t]=int(a[i]-'0');
	sort(b+1,b+1+t);
	for(int i=t; i>=1; i--)
		cout<<b[i];
	return 0;
}
