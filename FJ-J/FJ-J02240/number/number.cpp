#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int ans[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();++i)
		if('0'<=s[i]&&s[i]<='9'){
			ans[++cnt]=s[i]-'0';
		}
	sort(ans+1,ans+cnt+1);
	for(int i=cnt;i>=1;--i)cout<<ans[i];

	return 0;
}

