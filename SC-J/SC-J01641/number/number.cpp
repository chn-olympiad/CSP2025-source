#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int n,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++n]=s[i]-'0';
	sort(a+1,a+n+1,greater<int>());
	if(a[1]==0)
		cout<<0;
	else{
		string ans;
		for(int i=1;i<=n;i++)
			ans+=to_string(a[i]);
		cout<<ans;
	}
	return 0;
}