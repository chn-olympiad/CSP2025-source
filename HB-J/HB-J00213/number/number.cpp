#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int sum=0;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i] && s[i]<='9'){
            a[++sum]=s[i]-'0';
        }
    }
    sort(a+1,a+sum+1);
    for(int i=sum;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
