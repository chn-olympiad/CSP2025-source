#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cnt[102];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		char c=s[i];
		if(c>='0'&&c<='9')cnt[c-'0']++;
	} 
	for(int i=9;i>=0;i--){
		while(cnt[i]--)cout<<i;
	}
	return 0;
} 
