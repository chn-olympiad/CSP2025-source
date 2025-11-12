#include<bits/stdc++.h>
using namespace std;
int b[1000005],t;
string a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>=48&&a[i]<=57){
            b[t]=a[i]-48;
            t++;
        }
    }
    sort(b,b+t);
    for(int i=t-1;i>=0;i--) cout<<b[i];
    return 0;
}
