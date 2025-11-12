#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,a[20][20],b[110],k,w;
	cin>>n>>m;
	w=n*m;
	for(i=1;i<=n*m;i++)
    {
        cin>>b[i];
        if(i==1)
        {
            k=b[i];
        }
    }
    sort(b+1,b+1+n*m);
    j=1;
    for(i=1;i<=n;i++)
    {
        if(j==1)
        {
            for(j=1;j<=m;j++)
            {
                a[i][j]=b[w];
                if(b[w]==k)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                w--;
            }
        }
        else
        {
            for(j=m;j>0;j--)
            {
                a[i][j]=b[w];
                if(b[w]==k)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                w--;
            }
            j++;
        }
    }
    return 0;
}
