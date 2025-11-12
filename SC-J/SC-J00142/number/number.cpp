#include<bits/stdc++.h>
using namespace std;
const int N=2e6+15;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0,ss=s.size();
	for(int i=0;i<ss;i++)
	{
		int k=s[i]-'0';
		if(k>=0&&k<=9)
		{
			a[++cnt]=k;
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}