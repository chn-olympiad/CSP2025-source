#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	freopen("number.in","r",stdin);
//	freopen("ans.txt","w",stdout);
	string s;
	cin>>s;
	map<int,int>mp;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0' and s[i]<='9'){
			mp[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;--i){
		for(int j=1;j<=mp[i];++j) cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*

awa

114514

10086

qaq

rp++

*/
