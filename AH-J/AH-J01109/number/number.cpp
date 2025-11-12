#include <bits/stdc++.h>
using namespace std;
int t[11];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int i,len=s.size();
    for(i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
             t[s[i]-'0']++;
        }
    }
    for(i=9;i>=0;i--){
        for(int j=0;j<t[i];j++){
            cout<<i;
        }
    }
    return 0;
}
