#include<bits/stdc++.h>
using namespace std;

int bucket[10];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.length();
    for(int i=0;i<l;++i){
        if(s[i]>='0'&&'9'>=s[i]){
            bucket[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;--i){
        for(int j=0;j<bucket[i];j++){
            cout<<i;
        }
    }
    return 0;
}
