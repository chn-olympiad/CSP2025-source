#include<bits/stdc++.h>
using namespace std;
long long a[1000005],cnt=0;
string s;
bool cmp(long long n,long long m){
    return n>m;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&'0'<=s[i]){
            cnt++;
            a[i+1]=s[i]-'0';
        }
    }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)cout<<a[i];
    return 0;
}
