#include <bits/stdc++.h>
using namespace std;
string s;
int it;
short ans[1000003];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(unsigned i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') ans[++it]=s[i]-48;
	}
	sort(ans+1,ans+it+1,greater<int>());
	for(int i=1;i<=it;i++) cout<<ans[i];
	cout<<'\n';
	return 0;
}
