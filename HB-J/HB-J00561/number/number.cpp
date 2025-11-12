#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[N];
    cin>>s;
    int l=strlen(s);
    int a[l],c=0;
    for(ll i=0;i<l;i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[c]=s[i]-'0';
            c++;
        }
    }
    sort(a,a+c);
    for(ll i=c-1;i>=0;i--) cout<<a[i];
    return 0;
}