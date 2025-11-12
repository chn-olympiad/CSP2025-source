#include<iostream>
#define int long long
using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef local
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
	#endif
	string s;
	cin>>s;
	int a[10]{};
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
