#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cnt[9];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			if(s[i]=='0') cnt[0]++;
			else if(s[i]=='1') cnt[1]++;
			else if(s[i]=='2') cnt[2]++;
			else if(s[i]=='3') cnt[3]++;
			else if(s[i]=='4') cnt[4]++;
			else if(s[i]=='5') cnt[5]++;
			else if(s[i]=='6') cnt[6]++;
			else if(s[i]=='7') cnt[7]++;
			else if(s[i]=='8') cnt[8]++;
			else if(s[i]=='9') cnt[9]++;
		}
	}
	for(ll i=9;i>=0;i--){
		if(cnt[i]>0){
			for(ll j=1;j<=cnt[i];j++) cout << i;
		}
	}


	return 0;
}

