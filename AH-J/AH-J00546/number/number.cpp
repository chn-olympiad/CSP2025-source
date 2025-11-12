#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	LL len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')ans+=s[i];
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	cout<<ans;
	return 0;
}
