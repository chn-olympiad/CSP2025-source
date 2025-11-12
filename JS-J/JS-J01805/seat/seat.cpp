#include<bits/stdc++.h>
using namespace std;
int n,m,r,x,p=1,h,l;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    for(int i=2;i<=n*m;i++)
    {
        cin>>x;
        if(x>r)p++;
    }
    l=p/n;
    if(p%n>0)l++;
    if(l%2==1)h=p%n;
    else h=n-p%n+1;
    if(h==0)h=n;
    cout<<l<<" "<<h<<endl;
    return 0;
}
