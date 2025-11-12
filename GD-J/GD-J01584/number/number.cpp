#include<bits/stdc++.h>
#define psb push_back
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int N=1e6+5;
char s[N];
int n,cnt[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>(s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9')cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)while(cnt[i]--)cout<<i;
	return 0;
}
