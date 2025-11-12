#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],n;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[++n]=s[i]-'0'; 
	}
	sort(a+1,a+n+1,cmp);
	if(n>1&&a[1]==0) a[n=1]=0; 
	for(int i=1;i<=n;i++) cout<<a[i];
	return 0;
}
