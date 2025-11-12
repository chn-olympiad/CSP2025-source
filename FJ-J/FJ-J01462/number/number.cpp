#include <bits/stdc++.h>
using namespace std;
string s;
int len;
int a[10];
//string ans;
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
			if(i==0&&cnt==0) return 0;
			cnt=1;
		}
	}
//	if(ans[0]=='0') cout<<0;
//	else cout<<ans;
	return 0;
}

