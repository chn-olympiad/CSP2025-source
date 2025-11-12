#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],vv,mx;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=vv;j<i;j++){
            if((a[i]^a[j])==m){
                vv=i;
                mx++;
                break;
            }
        }
    }
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
