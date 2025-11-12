#include<bits/stdc++.h>
#define int long long 
using namespace std;
string s;
int a[1000002],cnt;
bool flag=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt);
	if(cnt==0) cout<<0;
	for(int i=cnt;i>=1;i--){
		if(flag&&a[i]==0){
			if(i==1) cout<<0;
			else continue;
		}
		else{
			flag=0;
			cout<<a[i];
		}
	}
	return 0;
}