#include <bits/stdc++.h>
using namespace std;
struct candidate{
    int id,score;
}a[105];
bool cmp(candidate x,candidate y){
    return x.score>y.score;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].score;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int rk=0;
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            rk=i;
            break;
        }
    }
    int c=(rk+n-1)/n,r=0,rest=rk%n;
    if(c&1){
        r=0;
        if(rest==0)
            r=n;
        else{
            for(int i=1;i<=rest;i++)
                r++;
        }
    }
    else{
        r=n+1;
        if(rest==0)
            r=1;
        else{
            for(int i=1;i<=rest;i++)
                r--;
        }
    }
    cout<<c<<' '<<r<<endl;
    return 0;
}
