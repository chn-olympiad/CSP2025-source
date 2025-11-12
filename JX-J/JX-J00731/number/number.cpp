#include<bits/stdc++.h>
using namespace std;
#define LL long long
string s;
char a[1000005];
LL n=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    LL len=s.length();
    for(LL i=0;i<len;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[n]=s[i];
            n++;
        }
    }
    sort(a,a+n);
    while(n--) cout<<a[n];
    return 0;
}
