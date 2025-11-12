#include<bits/stdc++.h>
using namespace std;
string s;
int n;
void ff(int x){
    for(int i=0;i<n;i++){
        if(s[i]==(x+'0'))cout<<x;
    }
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(int i=9;i>=0;i--){
        ff(i);
    }
}
