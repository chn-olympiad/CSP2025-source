#include<bits/stdc++.h>
using namespace std;
string s;
string as[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            as[s[i]-'0']+=s[i];
        }
    }
    for(int i=9;i>=0;i--){
        cout<<as[i];
    }
    fclose(stdin);
    fclose(stdout);
}
