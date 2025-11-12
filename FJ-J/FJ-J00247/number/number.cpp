#include <bits/stdc++.h>
using namespace std;
int cnt[10],n;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i = 0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			cnt[s[i]-'0']++;
	for(int i = 9;i>=0;i--) while(cnt[i]--) cout<<i;
	return 0;
}
