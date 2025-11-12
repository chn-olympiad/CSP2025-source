#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			ans.push_back(int(s[i]-'0'));
		}
	}
	sort(ans.begin(),ans.end(),greater<int>());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i];
		
	return 0;
}
