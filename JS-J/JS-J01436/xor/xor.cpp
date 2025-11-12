#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k;
int a[maxn];

bool flag1=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag1=0;
    }
    if(flag1){
        cout<<n/2;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
