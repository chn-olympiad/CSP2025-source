#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    char b[1000005];
    int n=0;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i]>='a' && s[i]<='z'){
            continue;
        }
        n+=1;
        b[n]=s[i];
    }
    sort(b+1,b+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout<<b[i];
    }
    return 0;
}
