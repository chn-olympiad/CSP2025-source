#include<bits/stdc++.h>
using namespace std;
int m,n,a[102],cnt,x=1,y=1;
bool b;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    cin>>a[1];
    for(int i=2;i<=m*n;i++)
    {
        cin>>a[i];
        if(a[i]>a[1]) cnt++;
    }
    while(1)
    {
        cnt--;
        if(b==0)
        {
            int xx=x+1;
            if(xx<=m) x=xx;
            else
            {
                y++;
                b=1;
            }
        }
        else
        {
            int xx=x-1;
            if(xx>0) x=xx;
            else
            {
                y++;
                b=0;
            }
        }
        if(cnt==0) break;
    }
    cout<<y<<' '<<x<<endl;
    fclose(stdin);fclose(stdout);
    return 0;
}
