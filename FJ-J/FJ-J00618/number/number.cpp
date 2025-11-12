#include<bits/stdc++.h>
using namespace std;
int b[10];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0; i<=s.size(); i++) {
		if(s[i]>='0' and s[i]<='9'){
		if(s[i]=='0'){
			b[0]++;
			continue;
		}
		if(s[i]=='1'){
			b[1]++;
			continue;
		}
		if(s[i]=='2'){
			b[2]++;
			continue;
		}
		if(s[i]=='3'){
			b[3]++;
			continue;
		}
		if(s[i]=='4'){
			b[4]++;
			continue;
		}
		if(s[i]=='5'){
			b[5]++;
			continue;
		}
		if(s[i]=='6'){
			b[6]++;
			continue;
		}
		if(s[i]=='7'){
			b[7]++;
			continue;
		}
		if(s[i]=='8'){
			b[8]++;
			continue;
		}
		if(s[i]=='9'){
			b[9]++;
			continue;
		}		
}
else
	continue;
}
	for(int i=9; i>=0; i--) {
		while(b[i]>0) {
			cout<<i;
			b[i]--;
		}
	}return 0;
	}
	