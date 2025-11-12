#include <bits/stdc++.h>
using namespace std;
int sm[15]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    bool f=true;
    for(int i=0;i < s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            sm[s[i]-'0']++;
            if(s[i]<='9'&&s[i]>='1'){
                f=false;
            }
        }
    }
    if(f){
        cout << 0;
        return 0;
    }
    else{
        for(int i=9;i >= 0;i--){
            while(sm[i]>0){
                cout << i;
                sm[i]--;
            }
        }
    }
    return 0;
}
