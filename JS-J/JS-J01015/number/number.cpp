#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;int tot=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0')a[++tot]=s[i]-'0';
    }
    sort(a+1,a+1+tot);
    for(int i=tot;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
