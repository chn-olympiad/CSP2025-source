#include<bits/stdc++.h>
using namespace std;
int a[1000],n,m,x=1,y=1,p=2,pro=-1,bn=-1;
string s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a+2,a+n*m+1);
    p=n*m;
    a[p+1]=a[1];
    for(int i=1;i<=n;i++)
    {
        if(y>1){
            pro=1;
        }
        else{
            pro=-1;
        }
        for(int j=1;j<=m;j++)
        {
            if(a[1]>=a[p]&&a[1]<=a[p+1])
            {
                bn=1;
                break;
            }
            p--;
            if(pro==-1){
                y++;
                if(y>m) y--;
            }
            else {
                y--;
                if(y<1) y++;
            }
        }
        if(bn==1)
        {
            break;
        }
        x++;
    }
    cout<<x<<" "<<y;
    return 0;
}
