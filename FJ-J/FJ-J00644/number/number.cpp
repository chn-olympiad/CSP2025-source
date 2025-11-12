#include<bits/stdc++.h>
using namespace std;
string a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-48]+=s[i];
		}
	}
	for(int i=9;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
