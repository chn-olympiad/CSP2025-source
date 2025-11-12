#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

void init__();
const ll size = 2e5 + 10;

int n, q = 0;
int ans = 0;
pair<string, string> arr[size];
string s1, s2;

bool cmp(pair<string,string>a, pair<string,string>b)
{
	return a.first[0] - '0' < b.first[0] - '0';
}

bool check(int num)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(arr[i].first[0] == s1[num])
		{
			int lent = arr[i].first.size();
			string ts1;
			for(int j = num; j < lent + num; j++)
				ts1 += s1[j];
			if(ts1 == arr[i].first)
				break;
		}
	}
	
	int len = arr[i].first.size();		
	string t_s1 = s1, ts2;
	for(int j = num; j < len + num; j++)
	{
		ts2 += s2[j];
	}
	if(arr[i].second == ts2)
	{

		for(int j = num; j < len + num; j++)
		{
			t_s1[j] = arr[i].second[j-num];
		}
	}
	if(t_s1 == s2)
		return true;
	else return false;
	
	
}

signed main()
{
	init__();
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr+n, cmp);
	
	while(q--)
	{
		ans = 0;
		cin >> s1 >> s2;
		for(int i = 0; i < s1.size(); i++)
		{
			int temp = ans;
			if(check(i))
			{
//				cout << i;
				ans++;
			}
//			if(ans != temp)
		}
		cout << ans << "\n";
	}
	
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
	
	cout << flush;
	return 0;
}

void init__()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
