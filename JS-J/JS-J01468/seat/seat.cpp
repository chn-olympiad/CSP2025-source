#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,qwer,qwe,fen,diji;
    cin>>n>>m;
    qwer=m*n;
    int ans[m+1][n+1],a[qwer+1];
    for(int i=1;i<=qwer;i++)
    {
        cin>>a[i];
    }
    fen=a[1];
    for(int i=1;i<qwer;i++)
    {
        for(int j=qwer-1;j>=1;j--)
        {
            if(a[j]<a[j+1])
            {
                qwe=a[j];
                a[j]=a[j+1];
                a[j+1]=qwe;
            }
        }
    }
    for(int i=1;i<=qwer;i++)
    {
        if(a[i]==fen)
        {
            diji=i;
            break;
        }
    }
    int hang=diji%n,lili;
    if(hang==0)
    {
        lili=diji/n;
    }
    else
    {
        lili=diji/n+1;
    }
    if(lili%2==0)
    {
        hang=n-diji%n+1;
    }
    cout<<lili<<" "<<hang;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
