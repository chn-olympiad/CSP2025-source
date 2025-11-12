#include<bits/stdc++.h>
using namespace std;
int a[1005],ans=0,cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c<=57&&c>=48){
            a[cnt]=c-48;
            cnt++;
        }
    }
    sort(a,a+cnt);
    for(int i=cnt-1;i>=0;i--){
        ans=ans*10+a[i];
    }
    cout<<ans;
    return 0;
}
