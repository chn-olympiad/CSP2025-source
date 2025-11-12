#include<bits/stdc++.h>
using namespace std;
string s;
long long n[15];
long long ans=0;
string t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(n[i]>0){
			for(int j=1;j<=n[i];j++){
				t+='0'+i;
			}
		}
	}
	cout<<t;
	return 0;
} 
