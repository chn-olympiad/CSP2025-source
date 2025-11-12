#include<bits/stdc++.h>
using namespace std;
struct stu{
    int id;
    int pro;
}a[10001];
int n,m,ans;
bool cmp(stu x,stu y){
    return x.pro>y.pro;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].pro;
        a[i].id=i;
    }
    sort(a+1,a+1+n*m,cmp);
    int h;
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            h=i;
            break;
        }
    }
    int lie=0,hang=0;
    if(h%n==0){
        lie=h/n;
        hang=n;
        if(lie%2==0){
            hang=1;
        }
    }
    else{
        lie=h/n+1;
        int u=h%n;
        hang=u;
        if(lie%2==0){
            hang=n+1-u;
        }
    }
    cout<<lie<<' '<<hang;
    return 0;
}
