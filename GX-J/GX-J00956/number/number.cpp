#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000000+5],op=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    long long p=s.size();
    for(int i=0;i<p;++i){
        char x=s[i];
        if((int)x>=48 and (int)x<=57){
            op++;
            a[op]=(int)x-48;
        }
    }
    sort(a+1,a+1+op);
    for(int i=op;i>=1;--i)cout<<a[i];
    return 0;
}
