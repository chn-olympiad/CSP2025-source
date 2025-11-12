#include<bits/stdc++.h>
using namespace std;
struct st{
    int d,id,idx;
};
st a[1100];
bool cmp(st x,st y){
    if(x.d!=y.d) return x.d>y.d;
    return x.id<y.id;
}
int main(){
    freopen("seat1.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sum;
    cin>>n>>m;
    sum=n*m;
    for(int i=1;i<=sum;i++){
        cin>>a[i].d;
        a[i].id=i;
    }
    sort(a+1,a+1+sum,cmp);
    for(int i=1;i<=sum;i++){
        a[i].idx=i;
        cout<<a[i].d<<' '<<a[i].id<<' '<<a[i].idx;
    }

    return 0;
}
