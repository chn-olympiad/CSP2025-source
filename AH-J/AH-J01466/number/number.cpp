#include <bits/stdc++.h>
using namespace std;
string s;
int ans[1000010],pos;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[++pos]=(s[i]-'0');
		}
	}
	sort(ans+1,ans+pos+1,greater<int>());
	for(int i=1;i<=pos;i++){
		cout<<ans[i];
	}
	return 0;
}
