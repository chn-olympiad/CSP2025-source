#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s = "";
    cin>>s;
    char x[1000000];
    stack<int> a;
    for(int i=0;i<=s.size();i++){
        x[i] = s[i];
        if((int)x[i]<48 || (int)x[i]>57) {
            x[i] = ' ';
        }
    }
    if(s.size()==1){
        cout<<x[0];
    }
    return 0;
}
