#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
    return a>b;
}
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    sort(s.begin(),s.end(),cmp);
    long long a;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'){
            a=i;
            break;
        }
    }
    for(int i=a;i<s.size();i++){
        cout<<s[i];
    }
    return 0;
}
