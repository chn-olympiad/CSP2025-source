#include<bits/stdc++.h>
using namespace std;
string s;
long long t[135];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        t[s[i]]++;
    }
    for(char i='9';i>='0';i--){
        if(t[i]>=1){
            for(int j=1;j<=t[i];j++){
                cout<<i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
