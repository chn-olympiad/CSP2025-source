#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long int b[1010],n=0,s=0;
	cin>>a;
	while(a[s]!=' ')
	{
		s++;
	}
	for(int i=0;i<s-1;i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			b[n]=a[i]-'0';
			n++;
		}
	}
	sort(b,b+n);
	for(int i=n-1;i>=0;i--)
	{
		cout<<b[i];
	}
	return 0;
}
