#include<iostream>
#include<string>
using namespace std;
int t[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            t[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(t[i]){
            t[i]--;
            cout<<i;
        }
    }

    return 0;
}
