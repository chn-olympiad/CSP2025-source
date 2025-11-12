#include<bits/stdc++.h>
using namespace std;
int t[15],n;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;n=s.size();
	for(int i=0;i<n;i++){t[s[i]-'0']++;}
	for(int i=9;i>=0;i--){while(t[i]){cout<<i,t[i]--;}}
	return 0;
}