#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.ans","w",stdout);
    int n,a[1000000];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<2*n-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
