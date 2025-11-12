#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005];

int main(){
    freopen("polyon.in","r",stdin);
    freopen("polyon.out","w",stdout);
    bool e=1;
    long long num=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    if(e!=1){
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                num++;
            }
        }
    }
    cout<<num;
    return 0;
}
