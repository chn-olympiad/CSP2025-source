#include<bits/stdc++.h>
//efine int long long
using namespace std;
int a[1000005]={},k=1;
string s,t="";
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])) a[k]=int(s[i])-48,k++;
    }
    sort(a+1,a+k+1);
    for(int i=2;i<=k;i++){
        t=to_string(a[i])+t;
    }
    cout<<t;
    return 0;
}
