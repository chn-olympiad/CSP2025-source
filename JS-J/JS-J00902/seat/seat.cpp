#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,p=0;
    cin>>n>>m;
    p=n*m;
    for(int i=1;i<=p;i++)
        cin>>a[i];
    int xa=a[1];
    sort(a+1,a+p+1);
    int xpai=p-(lower_bound(a+1,a+p+1,xa)-a)+1;
    int hang=(xpai%n!=0?xpai%n:n),lie=(xpai+n-1)/n;
    if(lie%2)
        cout<<lie<<' '<<hang;
    else
        cout<<lie<<' '<<n-hang+1;
    return 0;
}
