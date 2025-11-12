#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(char c){
    if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9') return true;
    return false;
}
int a[1000005];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long sum=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(check(s[i])) a[sum]=s[i]-'0',sum++;
    }
    sort(a,a+sum);
    for(int i=sum-1;i>=0;i--) cout<<a[i];
    return 0;
}
