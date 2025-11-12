#include<bits/stdc++.h>
#define N 1000005
using namespace std;
string s;
int a[N],t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-'0';
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--)
		printf("%d",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
