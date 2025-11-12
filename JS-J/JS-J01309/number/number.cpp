#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt=0;
    for(int t=0;t<s.size();t++){
        if(s[t]>='0' && s[t]<='9'){
            a[cnt]=s[t]-48;
            cnt++;
        }
    }
    sort(a,a+cnt);
    for(int t=cnt-1;t>=0;t--){
        cout<<a[t];
    }
    cout<<endl;
    return 0;
}
