#include<bits/stdc++.h>
using namespace std;
string s;
long long l[100005];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin>>s;
    long long n=s.size();
    for(int i=0; i<n; i++){
        if('0'<=s[i]&&s[i]<='9'){
            l[i]=s[i]-'0';
        }
        else break;
        sort(l+1,l+n+1);
        for(int i=n-1; i>=0; i--){
            cout<<l[i];
        }
    }
    return 0;
}
