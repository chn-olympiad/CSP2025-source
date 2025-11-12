#include<bits/stdc++.h>
using namespace std;
string a;
int pol[5005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size()-1;
	for(int i=0;i<=n;i++)if(a[i]>='0'&&a[i]<='9')pol[int(a[i]-'0')]++;
	for(int i=9;i>=0;i--)
	{
		string kl;
		for(int j=1;j<=pol[i];j++)kl+=char(i+'0');
		cout<<kl;
	}
	return 0;
}