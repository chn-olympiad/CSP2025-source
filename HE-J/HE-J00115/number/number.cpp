#include<bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string m,n;
	int a,b,c=1,d,k[100100];
	cin>>m;
	a=m.size();
	for(int i=0;i<a;i++)
	{
		if(m[i]>='0'&&m[i]<='9')
		{
			k[c]=m[i]-'0';
			c++;
		}
	}
	sort(k+1,k+c+1);
	for(int i=c;i>1;i--)
	{
		cout<<k[i];
	}
	return 0;
}
