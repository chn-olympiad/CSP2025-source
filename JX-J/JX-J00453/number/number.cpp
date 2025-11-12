#include<bits/stdc++.h>
using namespace std;
string s,ans;
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[(s[i]-'0')]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(a[i];a[i]>0;a[i]--){
            ans+=(i+'0');
            if(i==0&&ans=="0")break;
        }
    }
    cout<<ans;
    return 0;
}
