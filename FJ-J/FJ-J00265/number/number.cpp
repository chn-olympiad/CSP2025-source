#include<bits/stdc++.h>
using namespace std;
string s,ans;
int k,a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	k = s.size();
	for (int i = 0;i < k;i++)
	 if (s[i] >= '0' && s[i] <= '9') a[s[i] - '0']++;
	for (int i = '9';i >= '0';i--)
	 while (a[i - '0'] > 0) ans += i,a[i - '0']--;
	cout<<ans;
	return 0;
 }
