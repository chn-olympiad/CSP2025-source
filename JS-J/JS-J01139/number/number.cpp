#include <bits/stdc++.h>
using namespace std;
long long a[15];
string n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=0;i<n.length();i++){
        if(n[i]>='0'&&n[i]<='9'){
            a[n[i]-48]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(long long j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
