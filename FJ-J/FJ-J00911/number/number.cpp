#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
map<char,int>mp;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9'){
			mp[s[i]]++;
		}
	}
	string a="",b="";
	for(auto i:mp){
		while(i.second>0){
			i.second--;
			a=a+i.first;
		}
	}
	int t=a.size();
	for(int i=t-1;i>=0;i--){
		b=b+a[i];
	}
	cout<<b;
	return 0;
} 

