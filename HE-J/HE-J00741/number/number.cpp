#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
string s;
int a[N],ans;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans++;
			a[ans]=s[i]-'0';
		}
	}
	sort(a+1,a+1+ans);
	for(int i=ans;i>=1;i--)
	{
		if(i==ans&&a[i]==0)
		{
		cout<<0;
		break;	
		}
		cout<<a[i];
	}
	return 0;
}
