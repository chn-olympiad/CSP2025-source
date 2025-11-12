#include <bits/stdc++.h>
using namespace std;
int n=0,a[10001]={0};
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i-1];
        cout<<a[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
