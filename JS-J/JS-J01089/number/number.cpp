#include<bits/stdc++.h>
using namespace std;
string s;
int ans[15];
int i;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size(); i++){
		if('0'<=s[i]&&'9'>=s[i])
		ans[s[i]-'0']++;
	}
	for(i=9;i>=0;i--){
		for(int j=1;j<=ans[i];j++){
			printf("%d",i);
		}
	}
return 0;
}
