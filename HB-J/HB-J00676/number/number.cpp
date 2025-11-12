#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,c="",ans="";
    cin>>s;
    int l=0;
    char a[100003];
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[l]=s[i];
            l++;
        }
    }
    sort(a,a+l);
    for(int i=l-1;i>=0;i--){
        ans+=a[i];
    }
    cout<<ans;
}
