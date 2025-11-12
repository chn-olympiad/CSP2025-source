#include <iostream>
#include <string>

using namespace std;

string s;
int cnt[15];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9') cnt[s[i]-'0']++;
	}
	
	bool flg=0;
	for(int i=9;i>0;i--)
	{
		if(cnt[i]>0)
		{
			flg=1;
			for(;cnt[i]>0;cnt[i]--) cout<<i;
		}
	}
	
	if(flg) for(;cnt[0]>0;cnt[0]--) cout<<0;
	else cout<<0;
	
	return 0;
}
