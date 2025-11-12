#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=0,MOD=0,inf=0x3f3f3f3f;
int w[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<int(s.size());i++)
		if(s[i]>='0' && s[i]<='9') w[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(w[i]--) cout<<i;
	cout<<endl;
	return 0;
}
