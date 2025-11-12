#include<bits/stdc++.h>
using namespace std;
string s;
bool p=false;
int f[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		f[s[i]-'0']++;
    		if(s[i]!='0'){
    			p=true;
			}
		}
	}
	if(p==false){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(f[i]>0){
			cout<<i;
			f[i]--;
		}
	}
	return 0;
}
