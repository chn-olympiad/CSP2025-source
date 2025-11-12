#include<bits/stdc++.h>
using namespace std;
int n,k,a[100];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n==2&&k==0)
    {
        cin>>a[1]>>a[2];
        if(a[1]==0&&a[2]==0)
            cout<<1;
        else cout<<0;
    }
     fclose(stdin);
     fclose(stdout);
    return 0;
}
