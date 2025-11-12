#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[15];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	string ans="";
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			ans+=i+'0';
			a[i]--;
		}
	}
	cout<<ans;
	return 0;
} 