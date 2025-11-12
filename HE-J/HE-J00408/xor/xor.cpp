#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],s,p;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            p=p^a[j];
            if (p==k){
                s++;
                p=0;
                i=j;
                break;
            }
        }
    }
    cout<<s;
    return 0;
}
