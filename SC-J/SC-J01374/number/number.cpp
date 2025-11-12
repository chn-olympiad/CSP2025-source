#include<bits/stdc++.h>
using namespace std;
string a;
long long q[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]>='0'&&a[i]<='9')q[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=q[i];j++)	
			printf("%d",i);
	return 0;
}