#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
struct node
{
	int l,r;
};
vector<node> f;//[500005];
string xornum(string s1,string s2)
{
	int len1 = s1.length(),len2 = s2.length();
	string ans_str = "";
	int ml = min(len1,len2);
	if (len1 > len2)
	{
		ans_str = s1;
	}
	else 
	{
		ans_str = s2;
	}
	
	for (int i = 0;i < ml;i++)
	{
		if (s1[i] == s2[i] && s1[i] == '1')
			ans_str[i] = '0';
		else 
			ans_str[i] = '1';
	}
	return ans_str;
}
string ten_to_bit(int x)
{
	string ans_str1 = "";
	while (x > 0)
	{
		ans_str1 += x % 2 + '0';
		x -= x % 2;
		x /= 2;
	}
	//string ans_str2 = "";
	//int len = ans_str1.length();
	//for (int i = len - 1;i >= 0;i--)
	//	ans_str2 += ans_str1[i];
	return ans_str1;
}
int bit_to_ten(string str)
{
	int num = 0;
	int k = 0;
	int len = str.length();
	for (int i = 0;i < len;i++)
	{
		num += (str[i] - '0') * (1 << k);
		k++;
	}
	return num;
}
bool cmp(node a,node b)
{
	return a.r < b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k; 
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			string xorstr = "";
			for (int k1 = i;k1 <= j;k1++)
			{
				string str = ten_to_bit(a[k1]);
				if (xorstr == "")
					xorstr = str;
				else 
				{
					xorstr = xornum(xorstr,str);
				}
			}
			int num = bit_to_ten(xorstr);
			if (num == k)
				f.push_back({i,j});
		}
	}
	sort(f.begin(),f.end(),cmp);
	int s = f.size();
	int r = f[0].r;
	int ans = 1;
	for (int i = 1;i < s;i++)
	{
		if (f[i].l > r)
		{
			r = f[i].r;
			ans++;
		}
	}
	cout << ans;
	return 0;
}