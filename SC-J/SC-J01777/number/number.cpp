#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[1010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);			
	string s;
	cin>>s;
	int l=s.size();
	int j=0;
	for(int i=0;i<l;i++)
	{
		if(int(s[i])<='9'&&int(s[i])>='0')
		{
			a[j]=int(s[i])-'0';
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++) cout<<a[i];
	return 0;
 } 