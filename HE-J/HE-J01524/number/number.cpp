#include<bits/stdc++.h>
using namespace std;
const int N=10;
int t[N];
string s;
int main(){
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9')t[s[i]-'0']++;
	}
	for(int i=9;i>=0;--i)while(t[i]){
		t[i]--;
		cout<<i;
	}
	return 0;
}
