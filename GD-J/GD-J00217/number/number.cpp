#include<bits/stdc++.h>
using namespace std;
int ans[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			ans[i]=s[i]-48;
		else ans[i]=-1;
	} 
	sort(ans,ans+s.size());
	for(int i=s.size()-1;i>=0;i--)
		if(ans[i]>=0)cout<<ans[i];
	return 0;
}
