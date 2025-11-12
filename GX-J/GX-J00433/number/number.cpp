#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string char s, a, b;
    int c[1e6], d;
    cin >> s;
    d = len(s);
    for (int i=1; i<=d; i++){
    	if (s[i]>="0" && s[i]<="9"){
    	    c[i] = int s[i] - "0";
    	}
    }
    return 0;
}
