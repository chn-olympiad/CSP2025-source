#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long n=0;
    for(long long  i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[n]=int(s[i]-'0');
            n++;
        }
    }
    sort(a,a+n);
    for(long long i=n-1;i>=0;i--){
        cout<<a[i];
    }



}
