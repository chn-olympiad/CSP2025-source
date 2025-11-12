#include<bits/stdc++.h>
using namespace std;
string s;
bool f;
bool cmp(char a,char b){
    if(a>b)return 1;
    else return 0;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    char c;
    while(cin>>c){
        if(isdigit(c))s+=c;
        if(isdigit(c)&&c)f=1;
    }
    sort(s.begin(),s.end(),cmp);
    if(f)cout<<s<<endl;
    else cout<<0<<endl;
    return 0;
}