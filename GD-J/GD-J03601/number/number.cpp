#include<bits/stdc++.h>
#define ll long long
using namespace std;
int b[19];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin>>a;
	int l=a.length();
	for(int i=0;i<l;i++)
	{
		if('0'<=a[i] && a[i]<='9')
		b[(int)(a[i]-'0')]++;
	}
	for(int i=9;i>=0;i--)
	for(int j=b[i];j>=1;j--)
	cout<<i;
	
	fclose(stdin);fclose(stdout);
	return 0;
}
