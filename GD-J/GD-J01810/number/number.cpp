#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int cnt[1000005] , cnt1 = 0; 
signed main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.size();i++)
    {
    	if(s[i] >= '0' && s[i] <= '9')
    	{
    		cnt[cnt1] = s[i] - '0'; 
    		cnt1++;
		}
	}
	sort(cnt,cnt+cnt1);
	for(int i = cnt1-1;i >= 0;i--)
	{
		cout << cnt[i];
	}
	return 0;
} 
