#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int cnt[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9')cnt[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)while(cnt[i]--)cout<<i;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
