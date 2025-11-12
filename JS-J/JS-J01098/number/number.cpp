#include<bits/stdc++.h>
using namespace std;
string a;
char s[1000005];
long long b;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int si=a.size();
    for(int i=0;i<=si;i++){
        s[i]=a[i];
    }
    sort(s,s+si+1);
    int li;
    for(int i=si-1;i>=0;i--){
        li=int(s[i])-48;
        if(li>=0 && li<=9)cout<<li;
    }
}
