#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,a[105]={0},b[11][11]={0},c=0,d=0;
int main(){
     freopen("seat.in","r",stdin);
     freopen("seat.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<m*n;i++)
    {
        cin>>a[i];
    }
    c=a[0];
    sort(a,a+n*m);
    for(int i=m;i>=1;i--)
    {
        if(i%2!=0)
        {
            for(int j=n;j>=1;j--)
        {
            b[i][j]=a[d];
            if(a[d]==c)
            {
                cout<<i<<" "<<j;
            }
            d++;
        }
        if(i>=2)
        {
            i--;
            for(int j=1;j<=n;j++)
            {
               b[i][j]=a[d];
                if(a[d]==c)
                {
                     cout<<i<<" "<<j;
                }
                d++;
            }
        }
        }
        else{
           for(int j=1;j<=n;j++)
            {
               b[i][j]=a[d];
                if(a[d]==c)
                {
                     cout<<i<<" "<<j;
                }
                d++;
            }
        if(i>=2)
        {
            i--;
            for(int j=n;j>=1;j--)
        {
            b[i][j]=a[d];
            if(a[d]==c)
            {
                cout<<i<<" "<<j;
            }
            d++;
        }
        }
        }

    }

    return 0;
}
