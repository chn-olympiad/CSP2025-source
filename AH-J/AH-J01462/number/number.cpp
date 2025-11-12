#include"bits/stdc++.h"
using namespace std;
string s;
unordered_map<int,int>mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	int cnt=0;
	cin>>s;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]>='0'&&s[i]<='9')
			mp[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=mp[i];j++)
			printf("%d",i);
	}
	return 0;
}
