#include<bits/stdc++.h>
using namespace std;
//freopen´ò¿ªºõ£¿
int cnt[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')cnt[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(cnt[i]>0){
			for(int j=1;j<=cnt[i];j++)cout<<i;
		}
	}
	return 0;
}//operator priority
//290es1q0
