#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt[20];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
//	cout<<s<<endl;
	for(int i=0;i<s.size();i++){
		int p=s[i]-'0';
		if(p>=0 && p<=9) cnt[p]++;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]){
			cout<<i;
			cnt[i]--;
		}
	}
	return 0;
	
}