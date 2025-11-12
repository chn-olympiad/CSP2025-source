#include<iostream>
using namespace std;
int r,a[10005],t;
void dt(int x,int s,int B,int cs){
    if(s>2*B&&cs>=3)
        t++;
    for(int i=x+1;i<=r;i++){
        dt(i,s+a[i],max(a[i],B),cs+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>r;
    for(int i=1;i<=r;i++)
    cin>>a[i];
    for(int i=1;i<=r;i++)
    dt(i,a[i],a[i],1);
    cout<<t;
    return 0;
}
