#include <bits/stdc++.h>
using namespace std;
string s,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i=0;i<s.size();i++) if (s[i]>='0' && s[i]<='9') a+=s[i];
	int n=a.size();
	sort(a.begin(),a.end());
	for (int i=a.size()-1;i>=0;i--) cout << a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
