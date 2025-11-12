#include <bits/stdc++.h>
#include<string>
using namespace std;
int f[11];
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.length();
	for(int i=0;i<=len;i++)
		if('0'<=a[i]&&a[i]<='9')
			f[int(a[i]-'0')]++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=f[i];j++)
			printf("%d",i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//8:50 Íê³É 
