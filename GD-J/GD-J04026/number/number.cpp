#include<bits/stdc++.h>
using namespace std;
int a[1000005],len;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if('0'<=s[i]&&s[i]<='9') a[++len]=s[i]-'0';
	}
	sort(a+1,a+len+1);
	for(int i=len;i>=1;i--) printf("%d",a[i]);
	return 0;
}
