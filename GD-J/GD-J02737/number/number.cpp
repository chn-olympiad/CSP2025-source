#include<bits/stdc++.h>
using namespace std;
string s;
int ct[20];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ct[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(ct[i]--){
//			cout<<i;
			putchar(i+'0');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
