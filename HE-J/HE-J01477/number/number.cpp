#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],num,i,n;
int cmp(int b,int c)
{
	return b<c;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	n=s.size();
	for(i=0;i<n;i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			a[i]=s[i]-48;
			num++;
		}
	}
	sort(a,a+n,cmp);
	while(num--)
	{
		n--;
		printf("%d",a[n]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
