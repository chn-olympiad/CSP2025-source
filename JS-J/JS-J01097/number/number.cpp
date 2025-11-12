#include<bits/stdc++.h>
using namespace std;
long long sum[10];
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(long long i=0;i<a.size();i++) {
        if(a[i]>='0'&&a[i]<='9') sum[a[i]-'0']++;
    }
    for(long long i=9;i>=0;i--) for(long long j=0;j<sum[i];j++) cout<<i;
    return 0;
}