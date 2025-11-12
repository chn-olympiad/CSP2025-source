#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[ans]=s[i]-'0';
            ans++;
        }
    }
    sort(a,a+ans);
    for(int i=ans-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}