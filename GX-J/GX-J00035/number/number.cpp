#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string x;
    getline(cin,x);
    int n=x.length();
    int b[n]={-1};
    for (int i=0;i<n;i++) {
        if (x[i]>47 && x[i]<58) {
            b[i]=x[i]-48;
        }
        else {
            b[i]=-1;
        }
    }
    int t;
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-1;j++) {
            if (b[j]<b[j+1]) {
                t=b[j+1];
                b[j+1]=b[j];
                b[j]=t;
            }
        }
    }
    for (int i=0;i<n;i++) {
        if (b[i]==-1)continue;
        cout << b[i];
    }
    return 0;
}
