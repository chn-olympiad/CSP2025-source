#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod1 998244353
int cnt[10];
char s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//input here
	//main body here
	while(cin>>s) if(s>='0'&&s<='9') cnt[s-'0']++;
	//output here
	for(int i=9;i>=0;i--) while(cnt[i]--) cout<<i;
}
