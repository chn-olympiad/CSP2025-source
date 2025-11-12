#include<bits/stdc++.h>
using namespace std;
int n,m,ming;
int grade[105];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>ming;
    grade[1]=ming;
    for(int i=2;i<=n*m;i++) scanf("%d",&grade[i]);
    sort(grade+1,grade+1+n*m,cmp);
    int k=0;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
            for(int j=1;j<=n;j++)
            {
                k++;
                if(grade[k]==ming)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        else
            for(int j=n;j>=1;j--)
            {
                k++;
                if(grade[k]==ming)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
    }
    return 0;
}
