#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
inline bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin>>s;
    int len=s.size(),cnt=0;
    for(int i=0;i<len;++i){
        if(isdigit(s[i])){
            a[++cnt]=(s[i]-'0');
        }
    }
    stable_sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;++i){
        cout<<a[i];
    }
    return 0;
}
