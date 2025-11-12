#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a,b,c,;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
    }
    int m=max(a,max(b,c));
    if(a+b+c>m*2) cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
