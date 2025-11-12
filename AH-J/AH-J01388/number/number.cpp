#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	string ans;
	LL n=s.size();
	for(LL i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') ans+=s[i];
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	cout<<ans;
	return 0;
}
