#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=1e6+5;
string s;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s;
	for(char& ch:s){
		if(isdigit(ch))cnt[ch-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--)cout<<i;
	}
	cout<<'\n';
	return 0;
}
/*
note:
ÅÅÐò¡£ 
*/

