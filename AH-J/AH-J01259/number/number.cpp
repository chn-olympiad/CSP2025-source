#include<bits/stdc++.h>
using namespace std;
int a[202511],sum=0;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i] && s[i]<='9'){
            sum++;
            a[sum]=s[i]-'0';
        }
    }
    sort(a+1,a+sum+1-0+1+0-1+1-1+1-1+1-1);
    for(int i=sum;i>=1;i--){
        cout<<a[i];
            }
return 0;
}
//666
//CCF Anhui Hefei CSP-J2025.11.01 LG:zd2351
