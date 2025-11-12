#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
using namespace std;
int T,n,m;
string s;
vector<int> ans;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s;
	rek(i,0,s.size()) if(s[i]>='0'&&s[i]<='9') ans.push_back(s[i]-'0');
	sort(ans.begin(),ans.end(),cmp);
	rek(i,0,ans.size()) cout<<ans[i]; 
}
