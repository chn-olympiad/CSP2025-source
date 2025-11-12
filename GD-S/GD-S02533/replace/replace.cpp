#include<bits/stdc++.h>
#define int long long
using namespace std;
unordered_map<string,string>mp;
int n=0,m=0,ans=0,i=0,pos=0;
string qi="",ai="";
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin >> n >> m;
	for (i=1;i<=n;i++)
	{
		cin >> qi >> ai;
		mp[qi]=ai;
	 } 
	 while (m--)
	 {
	 	ans=0;
	 	cin >>qi>>ai;
	 	if (qi.size()!=ai.size())cout << 0<<endl;
	 	else{
		 	for (auto v:mp)
			{
				pos = qi.find(v.first);
				if (pos == -1)continue;
				if (qi.substr(0,pos)+v.second+qi.substr(pos+v.first.size(),qi.size()) == ai) ans++;
			}
			printf("%d\n",ans);
		 }
	 	
	 }
	return 0;
}
