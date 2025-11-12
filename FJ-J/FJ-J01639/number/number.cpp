#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=0;
	if(s.size()==0) return 0;
	for(int i=0;i<s.size();i++)
	 {
	 	if(s[i]>='0'&&s[i]<='9') a[++k]=s[i]-'0';
	 }
	 bool flag=0;
	sort(a+1,a+1+k,greater<int>());
	bool shuzi=0;
	for(int i=1;i<=k;i++)
	{
		if(flag==0&&a[i]==0) shuzi=1;
		else 
		{
			flag=1;
			cout<<a[i];
		}
	}
	if(shuzi==0)
	{
		return 0;
	}
	if(flag==0) cout<<0;
	return 0;
}

