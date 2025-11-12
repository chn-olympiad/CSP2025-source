#include<bits/stdc++.h>
using namespace std;
string s;
long long n[1000005];
long long a;
bool e(int A,int B){
    return A>B;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            n[a]=s[i]-'0';
            a++;
        }
    }
    sort(n,n+a,e);
    for(int i=0;i<a;i++)cout<<n[i];
    return 0;
}
