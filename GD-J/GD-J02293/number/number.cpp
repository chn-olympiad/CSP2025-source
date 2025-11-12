#include<bits/stdc++.h>
using namespace std;
string s;
map<int,long long> mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') mp[(int)s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=mp[i];j++) printf("%d",i);
	}
	
	return 0;
}
