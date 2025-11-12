#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
char sn[N];
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            sn[len]=s[i];
            len+=1;
        }
    }
    sort(sn,sn+len,cmp);
    cout<<sn;
    return 0;
}
