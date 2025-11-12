#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int l=s.size(),a[1000005],top=1,cntz=0;
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[top]=s[i]-'0';
            top++;
        }
    }
    top--;
    sort(a+1,a+top+1);
    for(int i=top;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
