#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y;
    cin>>x>>y;
    for(int i=0;i<x*y;i++){
        cin>>a[i];
    }
    int r=a[0];
    sort(a,a+x*y);
    reverse(a,a+x*y);
    for(int i=0;i<x*y;i++){
        if(a[i]==r)r=i+1;
    }
    //cout<<r<<endl;
    int hang=0,lie=0;
    lie=(r+x-1)/x;
    hang=r%x;
    if(hang==0)hang+=x;
    if(lie%2==0)hang=x+1-hang;
    if(lie%2==1)hang=hang;
    cout<<lie<<' '<<hang;
    return 0;
}
