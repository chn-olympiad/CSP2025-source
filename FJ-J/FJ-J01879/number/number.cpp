#include<bits/stdc++.h>

using namespace std;

int dingwei=0;
int a[1000005];

int c_o=0;
string s;
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int d=s.size();
	for(int i=0;i<d;i++)
	{
		int id=(int)s[i]-48;
		if(id>=1 && id<=9)
		{
			a[dingwei]=id;
			dingwei++;
		}
		if(id==0) c_o++;
	}
	sort(a,a+d,cmp);
	for(int i=d+1;i>=0;i--)
	{
		if(a[i]!=0) cout<<a[i];
	}
	if(!c_o) return 0;
	for(int i=1;i<=c_o;i++)
	{
		cout<<0;
	}
	return 0;
}
