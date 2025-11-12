#include<bits/stdc++.h>
using namespace std;
string s;
int n=0,ans=0;
char c[105];
bool cmp(char a,char b){
    return (int)a>(int)b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            c[n]=s[i];
            n++;
        }
    }
    sort(c,c+n-1,cmp);
    for(int i=0;i<n;i++){
            ans=ans*10+(int)c[i]-(int)'0';
    }
    cout<<ans;
    return 0;
}
