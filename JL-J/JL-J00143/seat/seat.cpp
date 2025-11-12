#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m;

struct node{
    int id,val;
    bool operator<(const node &x)const{
        return val>x.val;
    }
};
node a[maxn];
int st;
int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    cin>>a[i].val,a[i].id=i;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1) st=i;
    }
/*
    for(int i=1;i<=n*m;i++){
        cout<<a[i].val<<" ";
    }
    cout<<st;
    */
    int p=st/n;
    int q=st%n;
    //cout<<p<<q;
    if(q==0){
        p--;
        q+=n;
    }
    if(p&1){
        cout<<p+1<<" "<<n-q+1;
    }
    else{
        cout<<p+1<<" "<<q;
    }
    return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
