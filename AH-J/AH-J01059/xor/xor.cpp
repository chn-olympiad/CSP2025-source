#include<bits/stdc++.h>
using namespace std;
int a[500010];
long long he=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,js=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int m=i;m<=j;m++){
                he^=a[m];
            }
            if(he==k){
                js++;
                i=j;
                continue;
            }
            he=0;
        }
    }
    cout<<js;
    return 0;
}
