#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=9;i++)a[i]=0;
	string n;
	cin>>n;
	for(int i=0;i<=n.size()-1;i++)
	{
		if(n[i]<='9' and n[i]>='0')a[n[i]-'0']+=1;
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]--)
		{
			cout<<i;
		}
	}
 } 
