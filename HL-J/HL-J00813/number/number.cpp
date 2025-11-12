#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long a[100]={};
    long long len=s.size();
    for(long long i=0;i<=len;i++){
        a[int(s[i])]++;
    }
    for(int i=57;i>=48;i--){
        for(long long j=1;j<=a[i];j++){
            cout<<char(i);
        }
    }
    return 0;
}

