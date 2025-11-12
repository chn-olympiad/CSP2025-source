#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int b[1100000]={},s=0;
    cin>>a;
    int n=a.length();
    for(int i=0;i<n;i++){
        if(a[i]<=57 and a[i]>=48){
            b[s]=a[i]-48;
            s++;
        }
    }
    sort(b,b+s);
    for(int i=s-1;i>=0;i--){
        cout<<b[i];
    }
    return 0;
}
