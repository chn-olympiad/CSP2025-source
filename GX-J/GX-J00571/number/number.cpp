#include<bits/stdc++.h>
using namespace std;
string s,num;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    getline(cin,s);
    for(int i=0;i<=s.size();i++)
        if(s[i]-'0'>=0&&s[i]-'0'<=9)
            num+=s[i];
    sort(num.begin(),num.end(),cmp);
    cout<<num<<endl;
    return 0;
}
