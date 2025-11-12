#include<bits/stdc++.h>
using namespace std;
    string s;
    long long a[111111];
    long long b[111111],sum=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.size();i++){
        a[i]=s[i];
        if(a[i]>='0'&&a[i]<='9'){
            b[sum]=a[i]-'0';
            sum++;
        }
    }
    sort(b,b+sum);
    for(long long i=sum-1;i>=0;i--){
        cout<<b[i];
    }

    return 0;
}
