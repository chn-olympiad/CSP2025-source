#include<bits/stdc++.h>
using namespace std;
int c[1000001]={},o=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            c[o]=s[i]-'0';
            //cout<<c[o]<<" ";
            o++;
        }
    }
    sort(c,c+o);
    for(int i=o-1;i>=0;i--){
        cout<<c[i];
    }
    return 0;
}
