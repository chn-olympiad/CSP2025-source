#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){ 
		while(num[i]){
			cout<<i;
			num[i]--;
		}
	}
	return 0;
} 