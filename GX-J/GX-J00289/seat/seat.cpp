#include<bits/stdc++.h>
using namespace std;
int stu[0x7f][0x7f];
int test[0x7f];
int m,n;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<m*n;i++)
    {
        cin>>test[i];
    }
    int r=test[0];
    sort(test,test+n*m,cmp);
    for(int i=0;i<n;i++)
    {
        if(i%2==1)
        {
            sort(test+i*m-(m-1),test+i*m,cmp);
            for(int a=0;a<m;a++) stu[i][a]=test[i+m+a];
        }
        if(i%2==0)
        {
            sort(test+i*m-(m-1),test+i*m);
            for(int b=0;b<m;b++) stu[i][b]=test[i+m+b];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(stu[i][j]==r)
            {
                cout<<i+1<<" "<<j+1<<"\n";
                break;
            }
        }
    }
    return 0;
}
