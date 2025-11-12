#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string s;
int a[N];
int len=0,id=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			int t=s[i]-'0';
			a[++id]=t;
		}
	}
	sort(a+1,a+id+1,greater<int> ());
	for(int i=1;i<=id;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
