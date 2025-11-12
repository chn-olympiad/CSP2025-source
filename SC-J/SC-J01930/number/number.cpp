#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const bool ts=false;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	if(!ts){
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
	}
	//freopen("","w",stdout);
	string s;
	cin>>s;
	int a[10];
	memset(a,0,sizeof(a));
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			++a[s[i]-'0'];
		}
	}
	for(int i=9;i>=0;--i){
		while(a[i]--){
			cout<<i;
		}
	}
} 