#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long a[1000005]={0},in=0;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++in]=s[i]-'0';
        }
    }
    sort(a+1,in+a+1);
    for(long long i=in;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
