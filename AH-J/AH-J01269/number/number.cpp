#include<bits/stdc++.h>
using namespace std;
bool cmp(char c1,char c2){
    return c1>c2;
}
char ans[1000005]="";
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int len=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans[len++]=s[i];
        }
    }
    sort(ans,ans+len,cmp);
    for(int i=0;i<len;i++){
        cout<<ans[i];
    }
    return 0;
}

