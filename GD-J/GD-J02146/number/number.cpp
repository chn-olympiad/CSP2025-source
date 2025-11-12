#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt[10];
string s;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	bool flag=true,flag1=true;
	for(int i=1;i<=9;i++){
		if(cnt[i]) flag=false;
	}
	for(int i=0;i<=9;i++) {
		if(cnt[i]) flag1=false;
	}
	if(cnt[0]&&flag||flag1) {
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	return 0;
 } 
