#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m],z,i,x=1,y=1,num=1;
    cin>>z;
    a[0]=z;
    for(i=1;i<n*m;i++){
        cin>>a[i];
    }
    sort(a,a+n*m);
    i=n*m-1;
    while(true){
        y+=num,i--;
        if(y>n)x++,y-=1,num=-1;
        if(y<1)x++,y+=1,num=1;
        if(a[i]==z){
            cout<<x<<" "<<y;
            return 0;
        }
    }
}
