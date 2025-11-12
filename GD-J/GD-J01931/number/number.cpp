#include<bits/stdc++.h>
using namespace std;
string s,ans;
int cnt[10];
int main(){
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			ans+=('0'+i);
		}
	}
	cout<<ans;
	return 0;
} 
