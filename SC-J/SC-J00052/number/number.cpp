#include <bits/stdc++.h>
using namespace std;
int a[11]={0};
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[s[i]-'0']++;
		}
	} 
	int i=10;
	while(i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
	} 
//RP++