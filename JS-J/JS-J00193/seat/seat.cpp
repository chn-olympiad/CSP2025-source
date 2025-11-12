#include<bits/stdc++.h>
using namespace std;
int a[110],s[15][15];
int k;
int n,m;
int l=1;
bool f(int x,int y)
{
    return x>y;
}
int main( )
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>k;
    a[1]=k;
    for(int i=2;i<=n*m;i++) cin>>a[i];
    sort(a+1,a+n*m+1,f);
    for(int i=1;i<=m;i++)
    {
        if(i%2)
        {
            for(int j=1;j<=n;j++) s[i][j]=a[l],l++;
        }
        else
        {
            for(int j=n;j>=1;j--) s[i][j]=a[l],l++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i][j]==k) cout<<i<<" "<<j;
        }
    }
	return 0;
}
