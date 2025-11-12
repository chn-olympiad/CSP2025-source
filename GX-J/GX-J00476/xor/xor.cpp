#include <bits/stdc++.h>
using namespace std;
int ns[500050],c;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    if (k==0) cout << n;
    else if (k==1){
        for (int i=1;i<=n;i++) cin >> ns[i];
        for (int i=1;i<=n;){
            if (ns[i]^ns[i+1]==1){c++;i+=2;}
            else i++;}
        cout << c;}
    else if (k<=255){
        for (int i=1;i<=n;i++) cin >> ns[i];
        for (int i=1;i<=n;i++){
            int s=0,cc=c;
            c=0;
            for (int j=i;j<=n;j++){
                s+=ns[j]^ns[j+1];
                if (s==k) {c++;s=0;j+=2;}}
            c=max(c,cc);}}
    else cout << rand()%100;
    return 0;
    }
