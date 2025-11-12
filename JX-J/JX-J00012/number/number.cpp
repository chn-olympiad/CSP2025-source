#include<iostream>

using namespace std;

#define Debug 2
#define steam "number"

int b[11];

int main(){
	if (Debug == 1){
        string c;
        cin>>c;
		freopen((string(steam)+c+".in").c_str(),"r",stdin);
	} else if (Debug == 2) {
		freopen(steam".in","r",stdin);
		freopen(steam".out","w",stdout);
	}

    string s;
    cin>>s;
    for(int i =0;i<s.length();i++) {
        char c = s[i];
        if (c<='9'&&c>='0') {
            b[c-'0']++;
        }
    }
    string ans = "";
    for(int i=9;i>0;i--) {
        while (b[i]--){
            ans += char(i+'0');
        }
    }
    if (ans!="") while (b[0]--) {
        ans+='0';
    }

    cout<<(ans == ""?"0":ans);

	return 0;
}// 100 pts
// O(n)
