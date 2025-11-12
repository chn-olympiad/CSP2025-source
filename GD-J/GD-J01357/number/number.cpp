#include<bits/stdc++.h>

using namespace std;
string s;
vector<int> ans;
void ksort(int l, int r)
{
	int i = l, j = r, mid = ans[(l+r)>>1];
	while(i<=j)
	{
		while(ans[i]<mid)
		{
			i++;
		}
		while(ans[j]>mid)
		{
			j--;
		}
		if(i<=j)
		{
			swap(ans[i], ans[j]);
			i++;
			j--;
		}
	}
	if(i<r)
	{
		ksort(i, r);
	}
	if(l<j)
	{
		ksort(l, j);
	}
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for(int i = 0; i < len; i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans.push_back(s[i]-'0');
		}
	}
	len = ans.size();
	ksort(0, len-1);
	while(len>1&&ans[len-1]==0)
	{
		len--;
	}
	for(int i = len-1; i >= 0; i--)
	{
		cout << ans[i];
	}
	
	return 0;
}
