#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size(),now=1;
    for(int i=0;i<n;++i){
        if(s[i]>='0' && s[i]<='9'){
            a[now++]=s[i]-'0';
        }
    }
    --now;
    sort(a+1,a+now+1);
    for(int i=now;i>=1;--i) cout<<a[i];
    cout<<"\n";
    return 0;
}
