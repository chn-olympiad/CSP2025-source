#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int64_t n=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    char c;
    for(int64_t i=0;i < s.size();i++){
        c=s[i];
        if(c>=48&&c<=57){
            a[n]=c-48;
            n++;
        }
    }
    sort(a,a+n,greater<int>());
    for(int64_t i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
