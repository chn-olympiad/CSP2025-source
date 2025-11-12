#include <bits/stdc++.h>
using namespace std;
string s;
map<int,int> mp;
int mm(char c){
	int ans;
	if(c=='1') ans=1;
	if(c=='2') ans=2;
	if(c=='3') ans=3;
	if(c=='4') ans=4;
	if(c=='5') ans=5;
	if(c=='6') ans=6;
	if(c=='7') ans=7;
	if(c=='8') ans=8;
	if(c=='9') ans=9;
	if(c=='0') ans=0;
	return ans;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			mp[mm(s[i])]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(mp[i]){
			for(int j=1;j<=mp[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
