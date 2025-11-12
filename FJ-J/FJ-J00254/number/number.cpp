#include<bits/stdc++.h>
using namespace std;
#define int long long 
int num[20];

void solve1(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	return ;
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve1();
	return 0;
} 
