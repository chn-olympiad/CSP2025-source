#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	bool y1y1=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=1;i<=9;i++){
		if(a[i]) y1y1=1;
	}
	if(!y1y1){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
}

