#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string x;
    cin>>x;
    long long i,s=0;
    for(i=0;i<x.size();i++){
        if(x[i]>='0'&&x[i]<='9'){
            s++;
            a[s]=(x[i]-48);
        }
    }
    sort(a+1,a+s+1);
    for(i=s;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
