#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,mx,mi;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
                if(s[i]=='5') {
                        cout<<5;
                return 0;
                }
            if(s[i+1]>s[i]){
                mx=s[i+1];
                mi=s[i];
                cout<<mx<<mi;
            }
        }else if(s[i]>='a'&&s[i]<='z'){
            continue;
        }
    }
    return 0;
}
