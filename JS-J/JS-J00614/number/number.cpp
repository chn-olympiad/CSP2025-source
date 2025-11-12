#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long c=0;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[c]=s[i]-'0';
            c++;
        }
    }
    sort(a,a+c);
    for(int i=c-1;i>=0;i--) cout<<a[i];
    return 0;
}
