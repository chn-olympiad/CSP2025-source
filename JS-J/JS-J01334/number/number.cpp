#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=s.length()-1;
    for (int i=0;i<=len;i++){
		if (s[i]-'0'<='9' && s[i]-'0'>='1'){
			a[s[i]-'0']++;
		}
    }
    for (int i=9;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
