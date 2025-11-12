#include<bits/stdc++.h>
using namespace std;
string s,s1;
const int maxn=1e6+5;
int a[maxn];
bool cmd(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=0;
    for(int i=0;i<s.size();i++){
        if(48<=s[i]&&s[i]<=57){
            s1+=s[i];
            n++;
        }
    }
    for(int i=0;i<n;i++){
        a[i]=s1[i]-48;
    }
    sort(a,a+n,cmd);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
