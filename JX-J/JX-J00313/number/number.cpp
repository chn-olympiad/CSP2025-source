#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d,s1[1000010];
string s;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    a=s.size();
    for(int i=0;i<a;i++){
        if(s[i]<='9'&&s[i]>='0'){
            s1[b]=s[i]-'0',b++;
        }
    }
    sort(s1+0,s1+b);
    for(int i=b-1;i>=0;i--){
        printf("%lld",s1[i]);
    }
    return 0;
}
