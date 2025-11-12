#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
string s;
int s2[1919810];
int cnt = 0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i = 0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            s2[cnt] = s[i] - '0';
            cnt++;
        }
    }
    sort(s2,s2+cnt,cmp);
    for(int i=0;i<cnt;i++){
        cout<<s2[i];
    }
    return 0;
}