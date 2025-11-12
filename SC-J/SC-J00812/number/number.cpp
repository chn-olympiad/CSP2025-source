#include<bits/stdc++.h>
using namespace std;
string a;
int m=0,n[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9') 
		{
			n[a[i]-'0']++;
			if(a[i]!='0') m++;
		}
	}
	if(m==0) cout<<0;
	else for(int i=9;i>=0;i--) for(int j=1;j<=n[i];j++) cout<<i;
	return 0;
}