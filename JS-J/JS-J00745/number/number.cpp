/*
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool check(){
    for(int i = 0;i < v.size();i++){
        if(v[i] != 0) return false;
    }
    return true;
}
int main(){
    //freopen("number.in",'r',stdin);
    //freopen("number.out",'w',stdout);
    string s;
    cin>>s;
    for(int i = 0;i <= sizeof(s);i++){
        if(s[i]-'0' >= 0 && s[i]-'0' <= 9){
            v.push_back(s[i]-'0');
        }
    }
    if(check()){
        cout<<0;
        return 0;
    }
    sort(v.begin(),v.end());
    for(int i = v.size()-1;i >= 0;i--) cout<<v[i];
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
string s;
char c[100086];
bool cmp(char a,char b){
    return a > b;
}

bool check(){
    for(int i = 0;i < s.size();i++){
        if(s[i] != 0) return false;
    }
    return true;
}
int main(){
    cin>>s;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i = 0;i < s.size();i++){
        c[i] = s[i];
    }
    if(check()){
        cout<<0;
        return 0;
    }
    sort(c,c+s.size(),cmp);
    for(int i = 0;i < s.size();i++){
        if(c[i]-'0' >= 0 && c[i]-'0' <= 9) cout<<c[i];
    }
    return 0;
}
