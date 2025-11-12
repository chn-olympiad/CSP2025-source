#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s)
	if(i=='1'||i=='2'||i=='3'||i=='4'||i=='5'||i=='6'||i=='7'||i=='8'||i=='9'||i=='0')
	ans+=i;
	sort(ans.begin(),ans.end(),greater<char>());
	cout<<ans<<endl;
	return 0;
}
