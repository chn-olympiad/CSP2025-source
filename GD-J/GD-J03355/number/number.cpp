#include <bits/stdc++.h>
using namespace std;

int h[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int slen = s.length();
	for(int i = 0;i < slen;i++){
		if(s[i] == '0') h[0]++;if(s[i] == '1') h[1]++;if(s[i] == '2') h[2]++;if(s[i] == '3') h[3]++;if(s[i] == '4') h[4]++;
		if(s[i] == '5') h[5]++;if(s[i] == '6') h[6]++;if(s[i] == '7') h[7]++;if(s[i] == '8') h[8]++;if(s[i] == '9') h[9]++;
	}
	
	string sout;
	for(int i = 9;i >= 0;i--){
		while(true){
			if(h[i] == 0)
				break;
			sout+=to_string(i);
			h[i]--;
		}
	}
	cout<<sout;
	return 0;
}

