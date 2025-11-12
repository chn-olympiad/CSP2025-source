#include<bits/stdc++.h>
using namespace std;
int t[255];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		int x=s[i]-48;
		t[x]++;
	}
	string ans;
	for(int i=9;i>=1;i--){
		string str(t[i],i+48);
		ans+=str;
	}
	cout<<ans;
	return 0;
}
