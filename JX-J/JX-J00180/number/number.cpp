#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
string s;
int a[N];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        a[s[i]-48]++;
    }
    for(int i=9;i>=0;i--){
        while(a[i]--)
        cout<<i;
    }
    fclose(stdout);
    return 0;
}

