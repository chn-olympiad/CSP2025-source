#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000009],len=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')a[++len]=s[i]-'0';
    }
    sort(a+1,a+len+1);
    if(a[len]==0){
        cout<<0;
        return 0;
    }
    for(int i=len;i>=1;i--)cout<<a[i];
    return 0;
}
