#include<bits/stdc++.h>
using namespace std;
string a;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    sort(a.begin(),a.end(),cmp);
    for(auto i:a){
        if(i>=97&&i<=122){
            continue;
        }
        else{
            cout<<i;
        }
    }
    return 0;
}