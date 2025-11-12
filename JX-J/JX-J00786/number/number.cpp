#include <bits/stdc++.h>
using namespace std;
string s;
long long a[100001]={},m=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.size();i++){
         if(s[i]=='9' or s[i]=='8' or s[i]=='7' or s[i]=='6' or s[i]=='5' or s[i]=='4' or s[i]=='3' or s[i]=='2' or s[i]=='1' or s[i]=='0'){
            m=m+1;
            a[m]=s[i]-'0';
         }
    }
    for(long long i=1;i<=m;i++){
        for(long long l=1;l<=m;l++){
            if(a[l]<a[l+1]){
                swap(a[l],a[l+1]);
            }
        }
    }
    for(long long i=1;i<=m;i++){
         cout<<a[i];
    }
    return 0;
}
