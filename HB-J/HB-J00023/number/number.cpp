#include<bits/stdc++.h>
using namespace std;
long long a[1234567];
int main(){
    long long cnt=0,ans=1;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    s=" "+s;
    long long n=s.size()-1;
    for(long long i=1;i<=n;i++){
        if(s[i]>='0'&&s[i]<='9') {
            a[ans++]=s[i]-'0';
            cnt++;
        }
    }
    sort(a+1,a+1+cnt);
    for(long long i=cnt;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
