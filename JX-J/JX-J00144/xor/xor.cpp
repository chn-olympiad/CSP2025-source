#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,s=0;

    cin>> n>>k;
    int a[n+5];
    bool F1=true,F2=true;
    for(int i=1;i<=n;i++){
        cin>> a[i];

        if(a[i]==1)F1=false;
        if(a[i]>1)F2=false;
    }
    if(k==0){
        if(F1)cout << n;
        else if(F2){
            for(int i=1;i<n;i++){
                if(a[i]==0)s++;
                else if(a[i]==1&&a[i+1]==1)s++;
            }
            cout << s;
        }
    }

    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)s++;
        }
        cout << s;
    }
    return 0;
}

