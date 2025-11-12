#include<bits/stdc++.h>
using namespace std;
int c[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1; cin>>s1;
	vector<int> s;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			c[s1[i]-'0']++;
		}
	}
	bool f1=true;
	for(int i=1;i<=9;i++){
		if(c[i]){
			f1=false;
			break;
		}
	}
	if(f1){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(c[i]--)cout<<i;
	}
	return 0;
} 
