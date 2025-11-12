#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int num[15];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	
	for(int i = 0; i < s.size(); i++) {
		int e = int(s[i]);
		if(e >= '0' && e <= '9') num[e - '0']++;
	}
	
	for(int i = 9; i >= 0; i--) {
		for(int j = 1; j <= num[i]; j++) cout << i;
	}
	return 0;
}

