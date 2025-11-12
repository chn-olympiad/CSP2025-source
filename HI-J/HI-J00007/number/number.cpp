#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int c[15]={0},cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			c[s[i]-48]++;
			cnt++;
		}
	}
	for(int i=9;i>=0;i--){
		while(c[i]>0){
			cout<<i;
			c[i]--;
		}
	}
	return 0;
}
