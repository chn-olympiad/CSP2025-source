#include <bits/stdc++.h>
using namespace std;
string s;
long long a[10005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>0;i--){
        if(a[i]>=0){
            long long t=a[i];
            while(t--){
                cout<<i;
            }
        }
    }
    return 0;
}
