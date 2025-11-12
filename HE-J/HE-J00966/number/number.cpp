#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9')n[s[i]-'0']++;	
	}
	for(int i=9;i>=0;i--){
		while(n[i]--){
			cout<<i;
		}
	}
	return 0;
}

