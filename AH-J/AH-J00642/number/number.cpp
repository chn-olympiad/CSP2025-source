#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
unsigned long long ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		a[i]=s[i]-'0';
	sort(a,a+s.size());
	for(int i=len;i>=0;i--)
		if(a[i]<=9&&a[i]>=0)
			ans=ans*10+a[i];
	cout<<ans;
	return 0;
}
//16:00~20:00 4h
