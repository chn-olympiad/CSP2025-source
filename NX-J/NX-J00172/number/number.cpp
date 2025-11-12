#include<bits/stdc++.h>
using namespace std;
string s;
long long n,cnt,a[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;s[i];i++){
        if((s[i]>='0') && (s[i]<='9')){
            a[cnt++]=s[i]-'0';
            n++;
        }
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
