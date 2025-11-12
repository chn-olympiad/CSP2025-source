#include<bits/stdc++.h>
using namespace std;
string s;
int shuzi[11],jian;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			jian=int(s[i]-'0');
			shuzi[jian]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(;shuzi[i]>0;shuzi[i]--){
			printf("%d",i);
		}
	}
	return 0;
}
