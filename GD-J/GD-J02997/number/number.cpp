#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
using namespace std;

string s;
int p=0, num[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin >> s;
	for(int i=0; i<(signed)s.size(); i++){
		if('0' <= s[i] && s[i] <= '9') num[p] = s[i] - '0', p++;
	}
	sort(num, num+p);
	for(int i=p-1; i>=0; i--) cout << num[i];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
