/*
T1 sb题，先给数字提取出来排个序
理论上是橙题吧，注意前导0
9:41过大样例 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int a[N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin>>s;
	int n=s.size();
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
} 
