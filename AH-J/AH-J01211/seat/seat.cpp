#include<bits/stdc++.h>
using namespace std;
int n,m,zs,i,j,a,b,k;
int s[101],p[11][11];
bool t;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    zs=n*m;
    for(i=1;i<=zs;i++)
    {
        cin>>s[i];
    }
    k=s[1];
    for(i=1;i<=zs;i++)
        for(j=i+1;j<=zs;j++)
        {
            if(s[i]<s[j])
                swap(s[i],s[j]);
        }
    t=0;
    a=1;
    b=1;
    for(i=1;i<=zs;i++)
    {
        if(t==0)
        {
            if(a<=n)
            {
                p[a][b]=s[i];
                a++;
            }
            else{
                if(a==n+1)
                {

                    p[a-1][b+1]=s[i];
                    a=a-2;
                    b++;
                    t=1;
                }
            }
        }
        else
        {
            if(t==1)
            {
                if(a>0)
                {
                    p[a][b]=s[i];
                    a--;
                }
                else{
                    if(a==0)
                    {
                        p[a+1][b+1]=s[i];
                        a+=2;
                        b++;
                        t=0;
                    }
                }
            }
        }
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
           if(p[i][j]==k)
           {
               cout<<j<<" "<<i;
           }
        }
        fclose(stdin);
        fclose(stdout);
    return 0;
}
