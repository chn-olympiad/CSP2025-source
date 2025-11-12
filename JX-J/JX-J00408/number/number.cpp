#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
string s;
int a[N],cnt,n;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0' && s[i]<='9') a[++cnt]=(s[i]-'0');
	}
	sort(a+1,a+1+cnt,cmp);
	if(a[1]==0) cout<<"0\n";
	else
	{
		for(int i=1;i<=cnt;i++) cout<<a[i];
		cout<<"\n";
	}
	return 0;
}
