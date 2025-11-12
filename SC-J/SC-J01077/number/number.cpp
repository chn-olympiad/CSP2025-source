#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>47 && s[i]<58){
			cnt++;
			ans[cnt]=s[i]-48;
		}
	}
	sort(ans+1,ans+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
}