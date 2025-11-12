#include<bits/stdc++.h>
#define int long long
using namespace std;

string s;
int sum[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n = s.size();
	s = '#'+s;
	for(int i = 1; i<=n; i++){
		if(s[i]>='0' && s[i]<='9'){
			sum[s[i]-'0']++;
		}
	}
	bool h = false;
	for(int i = 9; i>=0; i--){
		if(sum[i]>0 && i != 0) h=true;
		if(i == 0 && !h){
			cout<<0;
			continue;
		}
		while(sum[i]>0){
			cout<<i;
			sum[i]--;
		}
	}
	cout<<endl;
	return 0;
}
