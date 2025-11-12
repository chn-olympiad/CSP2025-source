#include<bits/stdc++.h>
using namespace std;
int n,m;
int seat[100+5];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s=n*m;
    for(int i=0;i<s;i++)
    {
        cin>>seat[i];
    }
    int t=seat[0];
    sort(seat,seat+s,greater<int>());
    int x=1,y=1;
    bool isup=0;
    for(int i=0;i<s;i++)
    {
        if(seat[i]==t)
        {
            cout<<x<<" "<<y<<"\n";
        }
        else{
            
            if((y==n && !isup)|| (y==1 && isup))
            {
                
                !isup;
                x++;
                y=isup?n:1;
                continue;
            }
            if(isup)
            {
                y--;
            }
            else{
                y++;
            }
        }
    }
    return 0;
}