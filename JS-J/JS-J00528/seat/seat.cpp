#include <bits/stdc++.h>
using namespace std;
int n,m;
int R=0;
int cj[110];
int zw[110][110];
bool cmp(int p,int q)
{
    return p>q;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>cj[0];
    cj[n*m]=0;
    for(int i=1;i<(n*m);i++)
    {
        cin>>cj[i];
    }
    sort(cj+1,cj+1+n*m,cmp);
    for(int i=1;i<(n*m);i++)
    {
        if(cj[i]>=cj[0] && cj[i+1]<=cj[0])
        {
            R=i;
            for(int j=0;j<R;j++)
            {
                int tmp=cj[j];
                cj[j]=cj[j+1];
                cj[j+1]=tmp;
            }
            break;
        }
    }
    for(int y1=0;y1<m;y1++)
    {
        if(y1%2==0)
        {
            for(int x1=0;x1<n;x1++)
            {
                zw[x1][y1]=cj[y1*n+x1];
                if(y1*n+x1==R)
                {
                    cout<<y1+1<<" "<<x1+1;
                    break;
                }
            }
        }
        if(y1%2==1)
        {
            for(int x1=n-1;x1>=0;x1--)
            {
                zw[x1][y1]=cj[(y1+1)*n-x1-1];
                if((y1+1)*n-x1-1==R)
                {
                    cout<<y1+1<<" "<<x1+1;
                    break;
                }
            }
        }
    }
}
