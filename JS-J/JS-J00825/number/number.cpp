#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
string s;
int a[N],xb = 0;
bool cmp(int q,int w){
    return q > w;
}

signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i = 0;i < s.size();i ++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[++xb] = (s[i] - '0');
        }
    }
    sort(a + 1,a + xb + 1,cmp);
    if(a[1] == 0){
        cout<<0;
    }
    else{
        for(int i = 1;i <= xb;i ++){
            cout<<a[i];
        }
    }
    return 0;
}
