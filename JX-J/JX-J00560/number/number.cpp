#include <bits/stdc++.h>
using namespace std;
string s;
long long a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    //for(int i=9;i>=0;i--) cout<<a[i]<<" ";
    for(int i=9;i>=0;i--){
        if(a[i]!=0){
            while(a[i]--){
                cout<<i;
            }
        }
    }
    return 0;
}
