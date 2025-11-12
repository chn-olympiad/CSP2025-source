#include<bits/stdc++.h>
using namespace std;

string s;
int len,cnt;
int ans[1000006];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			ans[++cnt]=s[i]-'0';
		}
	}
	sort(ans+1,ans+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout << ans[i];
	}
	return 0;
}
