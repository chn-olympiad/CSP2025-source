#include<bits/stdc++.h>
using namespace std;
string a;
int t[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int lena=a.length(),i;
	for(i=0;i<lena;++i) if(a[i]>='0'&&a[i]<='9') ++t[a[i]-'0'];
	for(i=9;i>=0;--i)
	{
		while(t[i]--)
		{
			printf("%d",i);
		}
	}
	printf("\n");
	return 0;
}
