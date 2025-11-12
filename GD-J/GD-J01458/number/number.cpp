#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int c[1000005];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=0;
    for(int i=0;i<s.size();i++){
        char x=s[i];
        if(x>='0'&&x<='9'){
            c[l]=x-'0';
            l++;
        }
    }
    sort(c,c+l);
    for(int i=l-1;i>=0;i--){
        cout<<c[i];
    }
    return 0;
}
