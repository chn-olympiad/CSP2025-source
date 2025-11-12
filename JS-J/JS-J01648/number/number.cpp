#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
string s;
int cnt=0,ans=0;
int a[N];

bool cmp(int a,int b)
{
	return a<b;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s;
	int tmp = s.size();
	for(int i=0; i<tmp; i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			cnt++;
			a[cnt] = s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt; i>=1; i--)
	{
		
		cout << a[i];
	}
	cout << endl;
	return 0;
}
