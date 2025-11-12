#include<bits/stdc++.h>
using namespace std;
string s,s1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            s1+=s[i];
        }
    }
    for(int i='9';i>='0';i--){
        for(int j=0;j<s.size();j++){
            if(s1[j]==i){
                cout<<s1[j];
            }
        }
    }
    return 0;
}
