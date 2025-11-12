#include<bits/stdc++.h>
using namespace std;
int n,m,b[15][15],a[110];
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;int x;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    x=a[1];
    sort(a+1,a+1+(n*m),cmp);
    int o=(n*m);
    for(int i=1;i<=m;i++)
    {
        //cout<<i<<" ";
        if(i%2==0)
        {
            for(int j=n;j>0;j--)
            {
                b[i][j]=a[o];
                //cout<<b[i][j]<<" ";
                o--;
                if(b[i][j]==x)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                b[i][j]=a[o];
                //cout<<b[i][j]<<" ";
                o--;
                if(b[i][j]==x)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        if(o<0) break;
    }
    return 0;
}