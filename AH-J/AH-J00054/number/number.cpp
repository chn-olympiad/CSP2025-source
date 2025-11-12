#include <bits/stdc++.h>
using namespace std;
string s;

bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    sort(s.begin(),s.end(),cmp);
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            cout<<s[i];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
