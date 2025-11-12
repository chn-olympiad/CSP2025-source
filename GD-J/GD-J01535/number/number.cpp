#include<bits/stdc++.h>
using namespace std;
int c[11];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if(s[i]=='0') c[0]++;
		if(s[i]=='1') c[1]++;
		if(s[i]=='2') c[2]++;
		if(s[i]=='3') c[3]++;
		if(s[i]=='4') c[4]++;
		if(s[i]=='5') c[5]++;
		if(s[i]=='6') c[6]++;
		if(s[i]=='7') c[7]++;
		if(s[i]=='8') c[8]++;
		if(s[i]=='9') c[9]++;
	}
	for (int i=9;i>=0;i--){
		while(c[i]){
			cout<<i;
			c[i]--;
		}
	}
	return 0;
} 
