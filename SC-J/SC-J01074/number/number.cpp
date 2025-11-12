#include<bits/stdc++.h>
using namespace std;
int vis[15];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	bool flag=true;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]-'0'!=0)flag=false;
			vis[s[i]-'0']++;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<vis[i];j++){
			cout<<i;
		}
	}
	return 0;
}
