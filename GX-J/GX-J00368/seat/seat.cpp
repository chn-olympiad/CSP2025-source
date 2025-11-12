#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int c,r;
    cin>>c>>r;
    int a[c*r];
    for(int i=0;i<c*r;i++){
        cin>>a[i];
    }
    int R=a[0];
    sort(a,a+(c*r),cmp);
    if(a[0]=R) cout<<1<<" "<<1;
    else cout<<c<<" "<<r;
    return 0;
}
