#include<bits/stdc++.h>
using namespace std;
const int N=1e6+30;
string s;
int b[N],pos;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<s.length();i++){
       if(s[i]-'0'>=0&&s[i]-'0'<=9){
            b[++pos]=s[i]-'0';
       }
    }
    sort(b+1,b+1+pos,cmp);
    for(int i=1;i<=pos;i++){
        cout<<b[i];
    }
    return 0;
}
