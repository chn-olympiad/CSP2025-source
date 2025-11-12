#include<bits/stdc++.h>
using namespace std;
string s;
int t[11];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++) if(s[i]>='0'&&s[i]<='9') t[s[i]-'0']++;
	for(int i=9;i>=0;i--) if(t[i]!=0) for(int j=1;j<=t[i];j++) cout<<i;
	return 0;
}
//rp++; 
