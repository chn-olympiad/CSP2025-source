#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],seat[150][150],x=1,y=1,li,sun;
queue<int> q;
bool cmp(int a1,int a2)
{
    return a1>a2;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
        cin>>a[i];
    li=a[0];
    sort(a,a+(n*m),cmp);
    for(int i=0;i<n*m;i++)
        q.push(a[i]);//no problem
    while(!q.empty())
    {
            x++;
        if(seat[x][y]==li)
        {
            if(x>m)
                x--;
            if(y>n)
                y--;
            cout<<x<<" "<<y;
            return 0;
        }

        for(int i=0;i<n;i++)
        {
            seat[x][y]=q.front();
            if(seat[x][y]==li)
            {
                if(x>m)
                    x--;
                if(y>n)
                    y--;
                cout<<x<<" "<<y;
                return 0;
            }
            q.pop();
            if(sun%2==0)
                y++;
            else
                y--;
        }
        sun++;
    }
}
