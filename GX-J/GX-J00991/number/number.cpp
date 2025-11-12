#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    long long b[10];
    memset(b,0,sizeof(b));
    cin>>a;
    long long n;
    n=a.size();
    for(long long i=0;i<n;i++){
        if(a[i]>='0' && a[i]<='9'){
            b[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(b[i]--){
            cout<<i;
        }
    }
    return 0;
}
