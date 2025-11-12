#include<bits/stdc++.h>
using namespace std;
string s;
int x[1000010],t;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            x[t]=int(s[i]-'0');
            t++;
        }
    }
    sort(x,x+t);
    for(int i=t-1;i>=0;i--){
        cout<<x[i];
    }
    return 0;
}
