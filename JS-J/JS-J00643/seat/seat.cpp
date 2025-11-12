#include<bits/stdc++.h>
using namespace std;
int a[110],idi[110],n,m,idi1;
bool cmp(int x,int y){
    return a[x]>a[y];
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        idi[i]=i;
    }
    sort(idi+1,idi+1+n*m,cmp);
    idi1=idi[1];
    int x=(idi1+n-1)/n;
    int y=((idi1-1)%n)+1;
    if(x%2==0){
        y=m-y+1;
    }
    cout<<x<<" "<<y;
    return 0;
}
