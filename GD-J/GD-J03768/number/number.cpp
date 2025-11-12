#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int a[100010],s=1,z=0;
string st;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<=st.size();i++)
	{
		if(st[i]>='0'&&st[i]<='9')
		{
			a[s]=st[i]-'0';
			s++;
		}
	}
	sort(a+1,a+s,cmp);
	for(int i=1;i<s;i++)
	{
		z=z*10+a[i];
	}
	cout<<z;
	return 0;
} 
