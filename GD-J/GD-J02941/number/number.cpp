#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("r","number.in",stdin);
	freopen("w","number.out",stdout);
	cin>>s;
	int l=s.length(),t=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[t]=s[i];
			t++;
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
	return 0;
 } 
