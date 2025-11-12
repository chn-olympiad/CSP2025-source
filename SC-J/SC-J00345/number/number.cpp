#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000010];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int len=s.length();
	int cnt=0;
	for(int i=0;i<len;i++)
		if(isdigit(s[i])) a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1,greater<int>());
	if(a[1]==0){
		cout<<0<<'\n';
		return 0;
	}
	for(int i=1;i<=cnt;i++) cout<<a[i];
	return 0;
}
