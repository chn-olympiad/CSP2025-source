#include <bits/stdc++.h>
using namespace std;
string s,ans;
char f[1000005];
int a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a++;
            f[a]=s[i];
        }
    }
    sort(f+1,f+1+a);
    for(long long i=a;i>=1;i--){
        ans+=f[i];
    }
    cout<<ans;
    return 0;
}
