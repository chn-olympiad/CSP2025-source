#include<bits/stdc++.h>
using namespace std;
int n,m,a=1,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int s;
    cin>>n>>m>>s;
    int q;
    for(int i=2;i<=n*m;i++){
        cin>>q;
        if(q>s) a++;
    }
    c=(a-1)/n+1;
    if(c%2==1) r=(a-1)%n+1;
    else r=n-(a-1)%n;
    cout<<c<<' '<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
