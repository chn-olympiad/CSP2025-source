#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c;
    int xm,x=1,y=1;
    int a[100],a1[100];
    cin>>n>>m;
    int d;
    d=n*m;
    for(int i=0;i<d;i++)
    {
        if(i==0)
        {
            xm=a[0];
        }
        cin>>a[i];
    }
//cout<<a[1];
    c=a[0];
        for(int i=0;i<d;i++)
        {

            if(xm<a[i])
            {
                c++;
            }
        }
        for(int i=0;i<c;i++)
        {
            if(y%2==0)
            {
                x--;
                if(x=0)
                {
                    y++;
                }
            }
            else{
                x++;
                if(x=n)
                {
                    y++;
                }
            }
        }
    cout<<x+1<<' '<<y;
return 0;
}
