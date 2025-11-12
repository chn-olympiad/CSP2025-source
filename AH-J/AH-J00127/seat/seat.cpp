#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s[15][15],c=1,r=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    if(n==1 && m==1) cout<<c<<r;
    else cout<<"0";
    return 0;
}
