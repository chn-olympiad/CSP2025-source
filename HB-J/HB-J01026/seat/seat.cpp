#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,A[105],grid[N][N],mp[N][N],tmp;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>A[i];
    tmp=A[1];
    stable_sort(A+1,A+1+n*m,greater<int>());
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j&1)
            {
                grid[i][j]=(j-1)*n+i;
            }
            else
            {
                grid[i][j]=(j-1)*n+n-i+1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[grid[i][j]]==tmp)
            {
                cout<<j<<' '<<i<<endl;
                return 0;
            }
        }
    }
    return 0;
}
