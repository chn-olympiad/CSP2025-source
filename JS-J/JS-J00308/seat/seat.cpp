#include<bits/stdc++.h>
using namespace std;
int a=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int b,m,n,c;
    cin>>n>>m>>b;
    for(int i=1;i<n*m;i++)
    {
        cin>>c;
        if(c>b)a++;
    }
    c=1;
    int r=1;bool d=1;
    while(a)
    {
        r+=d*2-1;
        if(r==n+1||r==0){
            r-=d*2-1;
            c++;
            d=!d;
        }
        a--;
    }
    cout<<c<<" "<<r;
    return 0;
}
