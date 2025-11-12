#include<bits/stdc++.h>
using namespace std;
bool cmp(int w,int q)
{
	return w>q;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[100];
	int len=0;
	int l=0;
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++l]=s[i]-'0';
	sort(a+1,a+l+1,cmp);
	if(a[1]==0)
	{
		cout<<0;
		return 0;
	}
	int j;
	j=0;
	while(a[j]==0)
		j++;
	for(int i=1;i<=l;i++)
		cout<<a[i];
	return 0;
}
