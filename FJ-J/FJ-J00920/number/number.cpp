#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[10],cnt=0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=s.size();
	for(int i=0;i<k;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		cout<<i;
	}
	printf("\n");
	return 0;
}
