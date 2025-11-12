#include<bits/stdc++.h>
using namespace std;
int n,m,p,x=1,y=1,a[101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    p=a[1];
    sort(a+1,a+n*m+1);
    int i=n*m;
    while(a[i]>p)
    {
        i--;
        if(x%2==1)
        {
            if(y==n)
            {
                x++;
            }
            else
            {
                y++;
            }
        }
        else
        {
            if(y==1)
            {
                x++;
            }
            else
            {
                y--;
            }
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
