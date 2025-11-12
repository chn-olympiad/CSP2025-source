#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

//freopen("seat.in","r","stdin");
//freopen("seat.out","w","stdout");

int a[105],b[13][13];
int n,m,k=0;
bool cmt(int a,int b)
{
    return a>b;

}
int main()
{

    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n*m+1,cmt);
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                k++;
                b[i][j]=a[k];
            }
        }
        else
        {
            for(int z=1;z<=n;z++)
            {
                k++;
                b[i][z]=a[k];
            }
        }

    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(b[i][j]==a[1])
            {
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
