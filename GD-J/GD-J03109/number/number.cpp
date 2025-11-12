#include <bits/stdc++.h>
using namespace std;
int cnt[15];
string s;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9')cnt[s[i]-'0']++;
	}
	for(int k=9;k>=0;k++){
		if(k!=0){
			for(int i=1;i<=cnt[k];i++)cout<<k;
		}
	}
	return 0;
} 
