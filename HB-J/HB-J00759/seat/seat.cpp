#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;//n hang m lie
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int num=a[1];
    sort(a+1,a+n*m+1,cmp);
    int i=1,j=1;//i hang j lie
    for(int cur=1;cur<=n*m;cur++)
    {
        if(a[cur]==num)
        {
            cout<<j<<" "<<i<<endl;
            return 0;
        }
        if(j%2==1)
        {
            if(i==n)
            {
                j++;
            }
            else i++;
        }
        else
        {
            if(i!=1)
            {
                i--;
            }
            else
            {
                j++;
            }
        }
    }
    return 0;
}
