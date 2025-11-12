#include<bits/stdc++.h>
using namespace std;
int t[15];
string s;
bool check(){
	for(int i=9;i>=1;i--){
		if(t[i]>0)return 1;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	if(check()){
		for(int i=9;i>=0;i--){
			while(t[i]){
				cout<<i;
				t[i]--;
			}
		}
	}
	else cout<<"0";
	return 0;
}
