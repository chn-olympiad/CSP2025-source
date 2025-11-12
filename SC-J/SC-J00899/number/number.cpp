#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[15];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int num=s[i]-'0';
			a[num]++;
		}
	}
	string ans="";
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			ans+=i+'0';
			a[i]--;
		}
	}
	cout<<ans;
	return 0;
}