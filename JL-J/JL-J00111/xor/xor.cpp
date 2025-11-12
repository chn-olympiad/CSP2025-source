#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","e",stdin);
    freopen("number.out","w",stdout);
    int a,s,q;
    long long b[10000000000];
    cin >> a >> s;
    for (int i=0;i<=1000000000000;i++){
        cin >> z[i];
    }
    for (int i=0;i<=100000000000000;i++){
        for(int j=b[i];j<=1000000000000;i++){
            if(b[i]<b[i+1]){
                q=b[i];
                b[i]=b[i+1];
                b[i+1]=q;
        }
    }
    for (int i=0;i<=100000000000000;i++){
        if(b[i]!=s){
            cout << b[i];
            break;
        }
    }
    return 0;
}
