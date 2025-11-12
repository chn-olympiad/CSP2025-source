#include<bits/stdc++.h>
using namespace std;
string s;
int arr[1000005];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	int in = 1;
	for(int i = 0;i < len;i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			arr[in] = s[i] - '0';
			in++;
		}
	}
	
	sort(arr + 1, arr + in);
	for(int i = in-1;i >= 1;i--) cout << arr[i];
	
	return 0;
}
