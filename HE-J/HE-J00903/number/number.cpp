#include<bits/stdc++.h>
using namespace std;
char a[10000];
string s;
    int main(){
    freopen("member.in","r",stdin);
    freopen("member.out","w",stdout);
    cin>>s;
    if(s.size()==1){
        cout<<s;
        return 0;
    }
    int t;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            a[t++]=s[i];
        }
    }

    sort(a,a+t);
    for(int i=t;i>=0;i--){
        cout<<a[i];
    }

    return 0;
}
