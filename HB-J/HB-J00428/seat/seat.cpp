#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,m=1,n,f[1002];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>b;
    cin>>c;
    f[1]=c;
    while(cin>>n){
        m++;
        f[m]=n;
    }
    sort(f+1,f+m+1);
    for(int i=m;i>=1;i--){
        if(f[i]==c){
            d=m-i+1;
        }
    }
    if(d<=a)cout<<1<<" "<<d;
    else{
        cout<<d/a+1<<" ";
        if((d/a+1)%2==1)cout<<d%a;
        else cout<<a-d%a+1;
    }
    return 0;
}
