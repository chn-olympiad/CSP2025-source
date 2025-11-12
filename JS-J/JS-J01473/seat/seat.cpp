#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=225;


struct node{

    int scr,pos;
}a[N];
bool cmp(node a,node b){
    return a.scr>b.scr;
}
int main(){

freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].scr;
        a[i].pos=i;
    }
    int r_hang,r_lie;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].pos==1){
            r_lie=i/n+(i%n!=0);

            if(r_lie%2==0){
                r_hang=n-i%n+1;

            }else{
                r_hang=i%n+n*(i%n==0);

            }
            break;
        }//zhao_dao_xiao_r
    }
    cout<<r_lie<<" "<<r_hang;

    return 0;
}
