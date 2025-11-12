#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long n=0;
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if(isdigit(s[i])){
            n+=1;
        }
    }
    long long a[n];
    long long k=0;
    for(long long i=0;i<s.size();i++){
        if(isdigit(s[i])){
            a[k++]=s[i];
        }
    }
    sort(a,a+n);
    for(long long i=n-1;i>=0;i--)cout<<char(a[i]);
    return 0;
}
