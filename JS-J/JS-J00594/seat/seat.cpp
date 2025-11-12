#include<bits/stdc++.h>
using namespace std;
int n,m;
int seat_cspj[114];
int R_cspj;
int R_pos;
void init_op(int p)
{
    int R_l=(p%n==1)?p/n+1:p/n;
    int p2=p-((p%n==1)?R_l-1:R_l)*n;
    if(p2==0)
    {
        p2=n;
    }
    if((R_l)%2==1)
    {
        cout<<R_l<<" "<<p2;
        return;
    }
    else if((R_l)%2==0)
    {
        cout<<R_l<<" "<<n-p2+1;
        return;
    }
}
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>seat_cspj[i];
    }
    R_cspj=seat_cspj[1];
    int for_sorting=n*m;
    sort(seat_cspj+1,seat_cspj+1+for_sorting,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(R_cspj==seat_cspj[i])
        {
            R_pos=i;
        }
    }
    init_op(R_pos);
    return 0;
}
