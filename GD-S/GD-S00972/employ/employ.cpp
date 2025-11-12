#include<bits/stdc++.h>
using namespace std;
int n,m,c[501],ss[501];
bool s[501];
char S;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>S;
		s[i]=S-'0';
		ss[i]=ss[i-1]+(int)(s[i]);
	} 
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(n==m&&ss[i]-c[i]>0)
		{
			cout<<0;
			return 0;
		}
		
	}
	if(n==m)
	{
		cout<<1;
		return 0; 
	}
	cout<<2;
	return 0;
}


