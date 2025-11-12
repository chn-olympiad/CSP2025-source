#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,ans[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			ans[++cnt]=s[i]-'0';
	sort(ans+1,ans+cnt+1);
	for(int i=cnt;i>=1;i--)cout<<ans[i];
	return 0;
}
