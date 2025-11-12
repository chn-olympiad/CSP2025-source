#include<bits/stdc++.h>
using namespace std;

string s;

int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin >> s;
	if (s.length()==1){
        cout << s;
        return 0;
	}
	int f=0;
	int g[s.length()+1]={};
	for (int i=0;i<s.length();i++){
        if (s[i]>='a' && s[i]<='z'){
            g[f]=s[i]-'0';
            f++;
        }
	}
	int a=s.length();
	sort(g,g+a+1);
    for (int i=f;i>0;i--){
        cout << g[i];
    }

	return 0;
}
