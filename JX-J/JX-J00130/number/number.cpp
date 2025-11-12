#include<bits/stdc++.h>
#define lui long unsigned int
using namespace std;
int a[100010];
int tot;
bool cmp(int p,int q)
{
	return p>q;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(lui i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			tot++;
			a[tot]=s[i]-'0';
		}
	}
	sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=tot;i++)
		cout<<a[i];
	return 0;
}
