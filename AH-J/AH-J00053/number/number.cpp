#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin >> s;
	int k = 0;
	int l = s.size();
	for(int i = 0; i < l; i++)
	{
		if(s[i] >= '0' && s[i] <= '9') a[++k] = s[i] - '0';
	}
	sort(a + 1, a + 1 + k);
	if(a[k] == 0) {
		cout << 0;
		return 0;
	}
	for(int i = k; i >= 1; i--) 
	{
		cout << a[i];
		
	}
	return 0;
}
