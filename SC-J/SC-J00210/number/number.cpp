#include<bits/stdc++.h>
using namespace std;
int a[14];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(0<=s[i]-'0'<10){
			a[s[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		while(a[i]){
			cout<<i; 
			a[i]--;
		}
	}
	return 0;
} 