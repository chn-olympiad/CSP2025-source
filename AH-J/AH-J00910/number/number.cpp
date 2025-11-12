#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll sum[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') sum[s[i]-'0']++;
	for(ll i=9;i>=0;i--) if(sum[i]>0) while(sum[i]--) cout<<i;
	return 0;
}
