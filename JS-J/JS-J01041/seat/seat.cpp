#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int score;
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
        cin>>a[i];
    }
    score=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    int t=0;
    for(int j=1;j<=m;j++)
    {
        if(j%2==1)//down
        {
            for(int i=1;i<=n;i++)
            {
                t++;
                if(a[t]==score)
                {
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
            }
        }
        else //up
        {
            for(int i=n;i>=1;i--)
            {
                t++;
                if(a[t]==score)
                {
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
