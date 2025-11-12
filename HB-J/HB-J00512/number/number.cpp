#include "bits/stdc++.h"
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int ans[10]={ };
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=ans[i];j>0;j--)  cout << i;
    }
    return 0;
}
