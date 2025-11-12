#include <bits/stdc++.h>
using namespace std;
struct code{
    int fn,rn;
};
bool cmp(code x,code y){
    return x.fn>y.fn;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    code ru[n*m];
    for(int i=0;i<n*m;i++){
        cin>>ru[i].fn;
        ru[i].rn=0;
        ru[0].rn=1;
    }
    sort(ru,ru+n*m,cmp);
    int t;//paiming
    for(int i=0;i<n*m;i++){
        if(ru[i].rn){
            t=i;break;
        }
    }
    int lie=t/n+1,han=t%n+1;
    if(lie%2==0){
        han=n-han+1;
    }
    cout<<lie<<' '<<han;
    return 0;
}
