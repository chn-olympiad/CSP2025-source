#include <bits/stdc++.h>
using namespace std;
string q;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
           q+=s[i];
        }
    }
    sort(q.begin(),q.end(),cmp);
    cout<<q<<endl;
    return 0;
}
