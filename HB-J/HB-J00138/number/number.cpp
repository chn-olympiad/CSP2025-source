#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=strlen(s);
    sort(s,s+len+1);
    for(int i=len;i>0;i--){
        if(s[i]>='0'&&s[i]<='9'){cout<<s[i];}
    }
    cout<<'\n';
    return 0;
}