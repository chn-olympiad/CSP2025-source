#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') cnt[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++) cout<<i;
	}
	return 0;
}