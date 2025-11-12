#include<bits/stdc++.h>
using namespace std;
string s;
int t[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]<='9'&&s[i]>='0') t[s[i]-'0']++;
	}
	for(int i=9;i>=0;--i){
		while(t[i]!=0){
			cout<<i;
			--t[i];
		}
	}
	return 0;
}