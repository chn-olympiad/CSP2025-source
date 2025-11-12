#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5000];
int num[5000], pre[5000];
signed main()
{
	freopen("emplgy.in", "r", stdin);
	freopen("emplgy.out", "w", stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	int flag = 1;
		int cnt = 1;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 0; i < s.size(); i++){
		pre[i] = pre[i - 1];
		if(s[i] == '0')pre[i]++;
	}
	int tot = 0;
	for(int i = 1; i <= n; i++){
		if(a[tot] == 0){
			tot++;
			cnt++;
			continue;
		}
		if(a[tot] <= pre[i]){
			tot++;
			continue;
		}
		if(s[i] == '0'){
			cnt--;
		}
	}
	cout << rand();
}
