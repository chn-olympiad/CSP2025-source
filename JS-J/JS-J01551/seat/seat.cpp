#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int id;
    int l;
}a[105];
bool cmp(node x,node y){
    return x.l>y.l;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].l;
        a[i].id=i;
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            int p,ll;
            if(i<=n){
                cout<<1<<' '<<i;
                break;
            }
            int a=i%n;
            int l1;
            if(a==0){
                 l1=i/n;
            }
            else{
                l1=i/n+1;
            }

            if(l1%2==0){
                int p=i%(n+1);
                int ll=(i-p)/n+1;
                if(p==0)
                cout<<ll<<' '<<n;
            else
                cout<<ll<<' '<<n-p+1;
                break;
            }
            else{
                ll=i/n+1;
                p=i-(ll-1)*n;
                cout<<ll<<' '<<p;
            }
        }
    }
    return 0;
}
