#include<bits/stdc++.h>
using namespace std;
int a,num=0,ans[1111111];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if((int)s[i]<97){
            num++;
            ans[num]=(int)s[i]-48;
        }
    }
    sort(ans+1,ans+num+1);
    for(int i=num;i>=1;i--){
        cout<<ans[i];
    }
    return 0;
}
