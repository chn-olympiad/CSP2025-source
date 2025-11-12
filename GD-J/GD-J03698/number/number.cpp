#include<bits/stdc++.h>
using namespace std;
const int N=21;
string c;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	cin>>c;
	for(int i=0;i<c.size();i++)
	{
		if(48<=c[i]&&c[i]<=57)a[c[i]-48]++;
	}
//	for(int i=0;i<c.size();i++)cout<<c[i]<<" ";
	for(int i=9;i>=0;i--)
	{
		while(a[i]!=0)cout<<i,a[i]--;
	}
	return 0;
}
