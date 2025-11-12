#include <bits/stdc++.h>
using namespace std;
string s; int len=0,s1[1000020],mp[10];
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	/*
	for(int i = 0;i < s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){s1[len]=s[i]-'0'; len++;}
	}sort(s1,s1+len,cmp);
	for(int i = 0;i < len;i++) cout << s1[i];
	*/
	for(int i = 0;i < s.size();i++){
		if(s[i]>='0'&&s[i]<='9')mp[s[i]-'0']++;
	}
	for(int i = 9;i>=0;i--){
		for(int j = 1;j <= mp[i];j++) cout << i;
	}
	return 0;
}
