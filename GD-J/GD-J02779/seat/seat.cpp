#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1)  r=a[i];
    }sort(a+1,a+n*m+1,cmp);
    for(int i=1,j=1,cnt=1;cnt<=n*m;cnt++){
        if(i>n&&j%2==1) j++,i--;
        else if(i<1&&j%2==0) j++,i++;
        if(a[cnt]==r)  return cout<<j<<' '<<i,0;
        if(j%2==0)  i--;
        else  i++;
    }
    return 0;
}
