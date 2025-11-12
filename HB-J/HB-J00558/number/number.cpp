#include<bits/stdc++.h>
using namespace std;
string s;
int li[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			li[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(li[i]==0){
			continue;
		}
		for(int j=li[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
}
