#include<bits/stdc++.h>
using namespace std;
map<int,long long> mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int ans=s[i]-'0';
			mp[ans]++;
		}
	}
	for(int i=1;i<=mp[9];i++){
		cout<<9;
	}
	for(int i=1;i<=mp[8];i++){
		cout<<8;
	}
	for(int i=1;i<=mp[7];i++){
		cout<<7;
	}
	for(int i=1;i<=mp[6];i++){
		cout<<6;
	}
	for(int i=1;i<=mp[5];i++){
		cout<<5;
	}
	for(int i=1;i<=mp[4];i++){
		cout<<4;
	}
	for(int i=1;i<=mp[3];i++){
		cout<<3;
	}
	for(int i=1;i<=mp[2];i++){
		cout<<2;
	}
	for(int i=1;i<=mp[1];i++){
		cout<<1;
	}
	for(int i=1;i<=mp[0];i++){
		cout<<0;
	}
	return 0;
}

