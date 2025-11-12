#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int ans=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>'0'&&s[i]<9){
                a[ans]=s[i];
                ans++;
                }
    }
    sort(a+1,a+ans+1);
    for(int i=0;i<=ans;i++){
        cout<<s[i];
}
    return 0;
}
