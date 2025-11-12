#include<bits/stdc++.h>
using namespace std;

int cnt[10];
int ans;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){//record all numbers.
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){//output all numbers.
		while(cnt[i]--) cout<<i;
	}
	cout<<endl;
	return 0;
}