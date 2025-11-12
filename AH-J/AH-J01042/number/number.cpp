#include<bits/stdc++.h>
using namespace std;
const int e=1e7;
char a[e];
string b;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>b;
	int l=b.size();
	for(int i=0;i<l;i++)
	{	cin>>b[i];
		if(b[i]<='9'&&b[i]>='0')
		a[i]=b[i];
	}
	sort(a+1,a+1+l);
	for(int i=l-1;i>=0;i--)
	{	
		cout<<a[i];
	}
	return 0;
}
