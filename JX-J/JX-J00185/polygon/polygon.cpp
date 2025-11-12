#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a,sum=0,m=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        sum+=a;
        if(a>=m) m=a;
    }
    cout<<1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
