#include<bits/stdc++.h>
using namespace std;
struct seat{
    int sc,num;
}a[105];
int n,m,r,c;
bool cmp(seat x,seat y){
    return x.sc>=y.sc;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].sc;
        a[i].num=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].num==1){
            //cout<<i<<" "<<i%n<<" "<<i/n<<"\n";
            if(i%n==0){
                c=i/n;
            }else{
                c=(i/n)+1;
            }
            //cout<<c<<"\n";
            if(c%2==1){
                r=i%(2*n);
            }else{
                r=(i%(2*n))-n+1;
            }
        }
    }
    cout <<c<<" "<<r<<"\n";
    return 0;
}
