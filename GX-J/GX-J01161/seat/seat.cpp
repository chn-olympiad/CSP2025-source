#include <iostream>
using namespace std;
int n,i,j,k,m;
int a[11][11],b[1001];
int main()
{
	cin>>n>>m;
	for(i=1;i<=m;i++)
    {
        if(i%2==0)
        {
            for(j=n;j>=1;j--)
           {
               k++;
                a[i][j]=k;
            }
        }else{
           for(j=1;j<=n;j++)
        {
            k++;
                a[i][j]=k;
            }
        }


    }

	for(i=1;i<=n*m;i++)
	{
		cin>>b[i];
		k=b[1];
	}
	for(i=n*m;i>=1;i--)
    {
        for(j=1;j<=n*m;j++)
        {
            if(b[j]<b[j+1]) swap(b[j],b[j+1]);
        }
    }
    for(i=1;i<=n*m;i++)
    {
        if(k==b[i]) k=i;
    }
   for(i=1;i<=m;i++)
   {
       for(j=1;j<=n;j++)
       {
           if(k==a[i][j]) cout<<i<<" "<<j;
       }
   }
   return 0;
}

