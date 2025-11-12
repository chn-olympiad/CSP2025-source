#include<bits/stdc++.h>
using namespace std;
int mp[10];
string str;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]<='9'&&str[i]>='0') mp[str[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=mp[i];j++)
			cout<<i;
	}
	return 0;
}