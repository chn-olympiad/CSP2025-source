#include<iostream>
#include<algorithm>
using namespace std;
short a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n=0;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')a[++n]=s[i]-'0';
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	  printf("%d",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
