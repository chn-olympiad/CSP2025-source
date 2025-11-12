#include<bits/stdc++.h>
using namespace std;
string s;
int l[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')l[s[i]]++;
	}
	for(int i=57;i>=48;i--){
		while(l[i]!=0){
			l[i]--;
			cout<<i-48;
		}
	}
	return 0;
}