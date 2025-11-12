#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll f[15],i;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);//"\n";
	cin>>s;
	for(i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') f[s[i]-'0']++;
	for(i=9;i>=0;i--)
	  while(f[i]) 
		{
			f[i]--;
			cout<<i;
		}
	return 0;
 } 
