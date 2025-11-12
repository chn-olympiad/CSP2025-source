#include<bits/stdc++.h>
using namespace std;
const int maxn=9+10;
int n,cnt[maxn];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s; n=s.size();
	for(int i=1;i<=n;i++){
		char c=s[i-1];
		if(c>='0' && c<='9') cnt[c-'0']++;
	}
	for(int i=9;i>=0;i--) for(int j=1;j<=cnt[i];j++) printf("%d",i);
	return 0;
}