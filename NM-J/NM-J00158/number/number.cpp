#include<bits/stdc++.h>
using namespace std;
const int L=1e6+10;
char s[L];
long long n,a[L],p;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;s[i]!='\0';++i){
        if(s[i]>='a'&&s[i]<='z'){
            continue;
        }
        a[++p]=s[i]-'0';
    }
    sort(a+1,a+p+1);
    for(int j=p;j>=1;--j){
        cout<<a[j];
    }
    return 0;
}
