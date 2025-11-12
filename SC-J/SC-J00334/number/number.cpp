

#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<int,ll> mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			mp[str[i]-'0']++;
		}
	}
	bool f=0;
	for(int i=9;i>=1;i--){
		if(mp[i]){
			f=1;
			for(int j=1;j<=mp[i];j++){
				cout<<i;
			}
			
		}
		
	}
	if(f){
		for(int j=1;j<=mp[0];j++){
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
