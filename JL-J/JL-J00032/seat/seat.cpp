#include<bits/stdc++.h>
using namespace std;
int n,m,a,c,r=1;
int main(){
    freopen("seat.cpp","r",stdin);
    freopen("seat.cpp","w",stdout);
    cin>>n>>m>>a;
    if(a<=n)
        cout<<a<<r;
    else
        c=a/n;
        if(c%2==0)
            r=n-a%n;
            else
                r=a%n;
        cout<<c<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
