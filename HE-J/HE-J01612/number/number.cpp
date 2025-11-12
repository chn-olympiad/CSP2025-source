#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number3.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0,n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++cnt]=int(s[i]-'0');
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
		printf("%d",a[i]);
	return 0;
}
