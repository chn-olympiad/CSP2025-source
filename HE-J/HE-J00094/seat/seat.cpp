#include<bits/stdc++.h>
using namespace std;
long long i,j,n,m,c[122],cnt=1;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1; i<=n*m; i++)
    {
        cin>>c[i];
    }
    long long ans=c[1];
    sort(c+1,c+n*m+1,cmp);
    for(i=1; i<=m; i++)
    {
        if(i%2==0)
        {
            for(j=n; j>=1; j--)
            {
                if(c[cnt]==ans)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;
            }
        }
        else
        {
            for(j=1; j<=n; j++)
            {
                if(c[cnt]==ans)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
