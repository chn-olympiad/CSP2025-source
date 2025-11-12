#include<bits/stdc++.h>
using namespace std;
int n,t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]<='9') t[s[i]-'0']++;}
	for(int i=9;i>=0;i--){
		while(t[i]--){
			cout<<i;}}
	return 0;
} 