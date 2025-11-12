#include <bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
    return x>y;
}
string s,a;
long long ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a+=s[i];
        }
    }
    sort(&a[0],&a[a.size()],cmp);
    cout<<a;
    return 0;
}
