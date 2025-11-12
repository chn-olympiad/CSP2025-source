#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int i,a[1000001]={},b[10]={},f=0,j,mn=9,mx=0;
    cin>>s;
    for(i=0;i<s.length();i++){
        if((s[i]<='9')and(s[i]>='0')){
            f++;
            a[f]=s[i]-48;
            b[a[f]]++;
            mx=max(mx,a[f]);
            mn=min(mn,a[f]);
        }
    }
    for(i=mx;i>=mn;i--){
            if(b[i]>0){
               for(j=1;j<=b[i];j++){
                cout<<i;
            }
        }
    }
    return 0;
}
