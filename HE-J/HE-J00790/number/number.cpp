#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000005],ai;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(isdigit(s[i])){
			ans[ai++]=s[i]-'0';
		}
	}
	sort(ans,ans+ai);
	for(int i=ai-1;i>=0;i--){
		cout << ans[i];
	}
	return 0;
}
