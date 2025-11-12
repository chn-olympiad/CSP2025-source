#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int pos=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[pos++]=s[i]-'0';
		}
	}
	sort(ans,ans+pos);
	for(int i=pos-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
}
