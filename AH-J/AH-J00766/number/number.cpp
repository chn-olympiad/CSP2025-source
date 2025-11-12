#include<bits/stdc++.h>
using namespace std;
int ans[1001000];
int cnt = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			ans[++cnt] = s[i] - '0';
		}
	}
	sort(ans + 1,ans + 1 + cnt);
	if(ans[1] == 0){
		cout<<0<<endl;
	}else{
		for(int i = cnt;i >= 1;i--){
			cout<<ans[i];
		}
	}
	return 0;
}
