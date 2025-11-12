#include<bits/stdc++.h>
using namespace std;
int t[50],cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	cin>>s;
	memset(t,0,sizeof(t));
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(t[i]!=0){
			for(int j=1;j<=t[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
