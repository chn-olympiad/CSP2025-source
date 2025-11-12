#include<bits/stdc++.h>
using namespace std;
string s;
int pos=0;
char s1[1000005];
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            pos++;
            s1[pos]=s[i];
        }
    }
    sort(s1+1,s1+pos+1,cmp);
    for(int i=0;i<=pos;i++){
        cout<<s1[i];
    }
    return 0;
}
