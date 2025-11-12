#include<bits/stdc++.h>
using namespace std;
struct oi{
    int c1,r1,a1;
}a[105];
bool cmp(oi x,oi y){
    return x.a1>y.a1;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int c,r,cnt=0;
    cin>>c>>r;
    for(int i=1;i<=c;i++){
        for(int j=1;j<=r;j++){
            a[cnt].c1=i;
            a[cnt].r1=j;
            cin>>a[cnt].a1;
            cnt++;
        }
    }
    sort(a,a+c*r,cmp);
    cnt=0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[cnt].c1==1 && a[cnt].r1==1){
                if(i%2==0){
                    cout<<i<<" "<<c-j+1;
                }else cout<<i<<" "<<j;
            }
            cnt++;
        }
    }
    return 0;
}
