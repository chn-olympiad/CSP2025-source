#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll t[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			ll o = int(s[i]-'0');
			t[o]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(t[i]>0){
			for(int j=0;j<t[i];j++)cout<<i;
		}
	}
	return 0;
}
