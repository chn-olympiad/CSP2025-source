#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number3.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;

    char b[1000006];
    int n[1000006],k=0;
    int ln=a.size();
    for(int i=0;i<ln;i++){
        b[i]=a[i];

    }
    for(int i=0;i<ln;i++){
        if(b[i]>='0' && b[i]<='9'){
            n[k]=b[i]-'0';
            k++;
        }
    }
    sort(n,n+k);
    for(int i=k-1;i>=0;i--){
        cout<<n[i];
    }
    return 0;
}
