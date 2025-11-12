#include <bits/stdc++.h>
using namespace std;
int ls[1000001],cnt=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if (isdigit(s[i])){
            ls[cnt]=s[i]-'0';
            cnt++;
        }
    }
    sort(ls+1,ls+cnt,cmp);
    for(int i=1;i<cnt;i++){
        cout<<ls[i];
    }
}
