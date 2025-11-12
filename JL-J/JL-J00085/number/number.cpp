#include<bits/stdc++.h>
using namespace std;
const int K=1e6+10;
string s;
int a[K];
int num=0;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			num++;
			a[num]=(int)s[i]-48;
		}
	}
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--) cout<<a[i];
	return 0;
}
